//概述：调整数组顺序使奇数位于偶数前面
//题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

//解题：俩指针，前后扫描数组，前边的指针移动到偶数，后边的指针移动到奇数，然后交换，继续移动。
//时间复杂度：O(n)


// it's me.
void ReorderOddEven(int* pData, int length)
{
    if (nullptr == pData || length <= 0)
        return;

    int* pStart = pData;
    int* pEnd = pData + length - 1;
    while (pStart < pEnd)
    {
        while (pStart < pEnd && IsOdd(*pStart))
            ++pStart;

        while (pEnd > pStart && !IsOdd(*pEnd))
            --pEnd;

        if (pStart < pEnd)
        {
            int temp = *pStart;
            *pStart = *pEnd;
            *pEnd = temp;
        }
    }
}

bool IsOdd(int number)
{
    return number & 0x1;
}


//*************************************************************//
//method：以下设计具有可扩展性，可有用户定义判断条件。
void ReorderOddEven(int* pData, int length)
{
    Reorder(pData, length, IsOdd);
}

void Reorder(int* pData, unsigned int length, bool(*PFun)(int number))
{
    if (nullptr == pData || length == 0)
        return;

    int* pStart = pData;
    int* pEnd = pData + length - 1;
    while (pStart < pEnd)
    {
        while (pStart < pEnd && PFun(*pStart))
            ++pStart;

        while (pEnd > pStart && !PFun(*pEnd))
            --pEnd;

        if (pStart < pEnd)
        {
            int temp = *pStart;
            *pStart = *pEnd;
            *pEnd = temp;
        }
    }
}

bool IsEven(int number)
{
    return number & 1 == 0;
}
//*************************************************************//