//概述：替换空格
//题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.”

//解题思路：1.先遍历字符串，找出空格的个数，由此计算出替换之后的字符串的总长度。originalLength + numberOfBlank * 2
//2.从字符串的后面开始复制和替换。

//时间复杂度:O(n)

void ReplaceBlack(char str[], int length)
{
    if (nullptr == str || length <= 0)
        return;
    
    int numberOfBlank = 0;
    int originalLength = 0;
    while (str[originalLength] != '\0')
    {
        if (str[originalLength] == ' ')
            ++numberOfBlank;
        ++originalLength;
    }
    if (numberOfBlank <= 0)
        return;

    int newLength = originalLength + numberOfBlank * 2;
    if (newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (originalLength >= 0 && indexOfNew > indexOfOriginal)
    {
        if (str[indexOfOriginal] != ' ')
        {
            str[indexOfNew--] = str[indexOfOriginal];
        }
        else
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        --indexOfOriginal;
    }
    
    
}