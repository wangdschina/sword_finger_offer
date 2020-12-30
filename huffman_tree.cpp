//哈夫曼树的数据存储
struct HTNode
{
    HTNode()
    {
        weight = parent = leftchild = rightchild = 0;
    }
    int weight;
    int parent;
    int leftchild;
    int rightchild;
};
typedef HTNode* HuffmanTree;

void Select(HuffmanTree pHT[], int n, int& s1, int& s2)
{
    s1 = 0;
    s2 = 0;
    int i = 1;
    while (i <= n)
    {
        HTNode* pNode = pHT[i];
        if (pNode->leftchild != 0 && pNode->rightchild != 0)
        {
            if(0 == s1)
                s1 = i;
            else if (0 == s2)
                s2 = i;
            else
            {
                 if (pNode->weight <= pHT[s1]->weight)
                 {
                     s2 = s1;
                     s1 = i;
                 }
                 else if (pNode->weight < pHT[s2]->weight)
                 {
                     s2 = i;
                 }
            }            
        }
        ++i;
    }
}

//构造哈夫曼树
void CreteHuffmanTree(HuffmanTree& hfTree, int n)
{
    if (n <= 1)
        return;

    //初始化
    int m = 2*n - 1;
    hfTree = new HTNode[m + 1];    //简单点，0号不使用
    int i = 0;
    while(++i <= n)
        std::cin >> hfTree[i].weight;
    //end 初始化


    //开始创建哈夫曼树
    for (i = n + 1; n <= m; ++i)
    {
        int s1 = 0;
        int s2 = 0;
        Select(&hfTree, i - 1, s1, s2);  //在hfTree[k](1<=k<=i-1)中选择双亲域为0且权值最小的结点，并返回它们的下标

        hfTree[i].weight = hfTree[s1].weight + hfTree[s2].weight;
        hfTree[i].leftchild = s1;
        hfTree[i].rightchild = s2;
        hfTree[s1].parent = i;
        hfTree[s2].parent = i;
    }

}