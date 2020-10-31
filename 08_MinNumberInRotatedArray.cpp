//概述：旋转数组的最小数字
//题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

//解题思路：二分查找。
//时间复杂度：O(logn)

//it's me, it's fault.
//TODO：一些边界值没考虑全，特殊样例没考虑。
int Min(int* pData, int length)
{
    if (nullptr == pData || length <= 0)
        throw std::exception("Invalid Input");
    
    if (length == 1)
        return pData[length];

    int midIndex = length / 2;
    if (length - midIndex == 1)
    {
        return pData[0] >= pData[1] ? pData[1] : pData[0];
    }

    if (pData[midIndex] >= pData[0])
    {
        return Min(pData + midIndex + 1, length - (midIndex + 1));
    }
    if (pData[midIndex] <= pData[length - 1])
    {
        return Min(pData, length - midIndex);
    }
    return pData[midIndex];
}

//right method
int Min(int* pData, int length)
{
    if (nullptr == pData || length <= 0)
        throw std::exception("Invalid parameters.");

    int startIndex = 0;
    int endIndex = length - 1;
    int midIndex = startIndex; //如果数组本身是排序好的，也就是把0个元素旋转，所以需要设置为0，可以直接返回。
    while (pData[startIndex] >= pData[endIndex])
    {
        if (endIndex - startIndex == 1)
        {
            midIndex = endIndex;
            break;
        }

        //如果下标为startIndex、endIndex和midIndex指向的三个数字相等，
        //则只能顺序查找
        if (pData[startIndex] == pData[endIndex] && pData[startIndex] == pData[midIndex])
            return MinInOrder(pData, startIndex, endIndex);

        midIndex = (startIndex + endIndex) / 2;
        if (pData[midIndex] >= pData[startIndex])
            startIndex = midIndex;
        else if (pData[midIndex] <= pData[endIndex])
            endIndex = midIndex;
    }

    return pData[midIndex];
    
}

//需要处理{1,0,1,1,1} or {1,1,1,0,1}这种情况，必须顺序查找
int MinInOrder(int* pData, int startIndex, int endIndex)
{
    int result = pData[startIndex];
    int index = startIndex;
    while (++index <= endIndex)
    {
        if (pData[index] < result)
            result = pData[index];
    }
    
    return result;
}
