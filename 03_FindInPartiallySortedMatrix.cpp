//概述：二维数组中的查找

//题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

//解题思路：从数组右上角或者左下角开始查找
//时间复杂度：O(n)

//方法一：从右上角开始查找
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;
    if (nullptr != matrix && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            int nCurValue = matrix[row * columns + column];
            if (nCurValue == number)
            {
                found = true;
                break;
            }
            else if (nCurValue > number)
            {
                --column;
            }
            else
            {
                ++row;
            }
        }
    }
    
    return found;
}

//方法二：从左下角开始查找
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;
    if (nullptr != matrix && rows > 0 && columns > 0)
    {
        int row = rows - 1;
        int column = 0;
        while (row >= 0 && column < columns)
        {
            int nCurValue = matrix[row * columns + column];
            if (nCurValue == number)
            {
                found = true;
                break;
            }
            else if (nCurValue > number)
            {
                --row;
            }
            else
            {
                ++column;
            }
        }
    }
    
    return found;
}