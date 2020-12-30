//重建二叉树
//题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

//思路:在二叉树的前序遍历序列中，第一个数字总是树的根结点的值。
//但在中序遍历序列中，根结点的值在序列的中间，左子树的结点的值位于根结点的值的左边，而右子树的结点的值位于根结点的值的右边。
//因此我们需要扫描中序遍历序列，才能找到根结点的值。
//找到中序遍历中根节点的值之后，从而确定根节点的值的位置。这样就在前序遍历和中序遍历中分别找到了左右子树对应的子序列。
//既然分别找到了左右子树的前序遍历和中序遍历序列，可以用同样的方法分别去构建左右子树，也就是说，接下来的事情可以用递归的方法去完成。

//时间复杂度：O(n)

struct BinaryTreeNode
{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (nullptr == preorder || nullptr == inorder || length <= 0)
        return nullptr;
    
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(
    int* startPreorder, 
    int* endPreorder, 
    int* startInorder, 
    int* endInorder)
{
    //前序遍历的第一个数字是根节点的值
    int nRootValue = startPreorder[0];
    BinaryTreeNode* pRoot = new BinaryTreeNode;
    pRoot->m_nValue = nRootValue;
    pRoot->m_pLeft = nullptr;
    pRoot->m_pRight = nullptr;
    if (startPreorder == endPreorder)
    {  
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return pRoot;
        else
            throw std::exception("Invalid Input");
    }
    
    //在中序遍历中找到根节点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != nRootValue)
        ++rootInorder;
    if (rootInorder == endInorder && *rootInorder != nRootValue)
        throw std::exception("Invalid Input");

    int leftLength = rootInorder - startInorder;
    int* leftPreorder = startPreorder + leftLength;
    if (leftLength > 0)
    {
        //构建左子树
        pRoot->m_pLeft = ConstructCore(startPreorder + 1, leftPreorder, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        //构建右子树
        pRoot->m_pRight = ConstructCore(leftPreorder + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return pRoot;
}