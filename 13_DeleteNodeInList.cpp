//概述：在O（1）时间删除链表结点
//题目：给定单向链表的头指针和一个结点指针，定义一个函数在 O（1）时间删除该结点。

//解题：可以把要删除节点的下个节点的数据拷贝到要删除的节点，然后删除下个节点。
//时间复杂度：O(1)

struct ListNode
{
    int         m_nValue;
    ListNode*   m_pNext;
};


//it's me.未考虑删除尾节点的情况
void DeleteListNode(ListNode** pListHead, ListNode* pToBeDelete)
{
    if (nullptr == pListHead || nullptr == *pListHead || nullptr == pToBeDelete)
        return;

    if (*pListHead == pToBeDelete)
    {
        *pListHead = nullptr;
        delete pToBeDelete;
        pToBeDelete = nullptr;
        return;
    }

    ListNode* pNextNode = pToBeDelete->m_pNext;
    if (nullptr == pNextNode)
    {
        delete pToBeDelete;
        pToBeDelete = nullptr;
        return;
    }

    pToBeDelete->m_nValue = pNextNode->m_nValue;
    pToBeDelete->m_pNext = pNextNode->m_pNext;
    delete pNextNode;
    pNextNode = nullptr;
}

//method
void DeleteNode(ListNode** pListHead, ListNode* pToDeleted)
{
    if (nullptr == pListHead || nullptr == pToDeleted)
        return;

    //要删除的不是尾节点
    if (pToDeleted->m_pNext != nullptr)
    {
        ListNode* pNex = pToDeleted->m_pNext;
        pToDeleted->m_nValue = pNex->m_nValue;
        pToDeleted->m_pNext = pNex->m_pNext;
        delete pNex;
        pNex = nullptr;
    }
    else if (pToDeleted == *pListHead) //链表只有头结点
    {
        delete pToDeleted;
        pToDeleted = nullptr;
        *pListHead = nullptr;
    }
    else    //链表中有多个节点，删除尾节点
    {
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToDeleted)
        {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = nullptr;
        delete pToDeleted;
        pToDeleted = nullptr;
    }
}