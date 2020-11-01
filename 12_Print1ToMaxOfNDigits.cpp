//概述：打印1到最大的n位数
//题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数即999。

//解题：最常用也是最容易的方法是用字符串或者数组表达大数。
//时间复杂度：

void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;

    char * number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    
    while (!Increment(number))
    {
        PrintNumber(number);
    }
    delete []number;
}

bool Increment(char* number)
{
    bool isOverFlow = false;    //是否溢出
    bool isTakeOver = false;    //是否产生进位
    int length = strlen(number);
    for (int i = length - 1; i >= 0; --i)
    {
        int sum = number[i] - '0' + (isTakeOver ? 1 : 0);
        if (i == length - 1)
            ++sum;

        if (sum >= 10)  //判断是否需要进位
        {
            if (i == 0) //判断是否溢出，调用 strcmp 的时间复杂度是 O(n)，该时间复杂度是 O(1)
            {
                isOverFlow = true;
                break;
            }
            else
            {
                sum -= 10;
                isTakeOver = true;
                number[i] = '0';
            }
        }
        else
        {
            number[i] = '0' + sum;
            break;
        }
    }

    return isOverFlow;
}

void PrintNumber(char* number)
{
    if (nullptr == number)
        return;

    int length = strlen(number);
    bool isBegginning0 = true;  //判断从哪个位置开始打印
    for (int i = 0; i < length; ++i)
    {
        if (isBegginning0 && number[i] != '0')
            isBegginning0 = false;
        
        if (!isBegginning0)
            printf("%c", number[i]);
    }
    printf("\t");
}


//****************************************************************//
//把问题转换成数字排列的解法，递归让代码更简洁
void Print1ToMaxOfNDigits(int n)
{
    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    for (int i = 0; i < 10; i++)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
    

    delete []number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}
//****************************************************************//


//本题扩展：
//在前面的代码中，我们都是用一个char型字符表示十进制数字的一位。
//8个bit的char型字符最多能表示256个字符，而十进制数字只有0～9的10个数字。
//因此用char型字符串来表示十进制的数字并没有充分利用内存，有一些浪费。有没有更高效的方式来表示大数？


//相关题目：
//定义一个函数，在该函数中可以实现任意两个整数的加法。由于没有限定输入两个数的大小范围，我们也要把它当做大数问题来处理。
//在前面的代码的第一个思路中，实现了在字符串表示的数字上加 1 的功能，我们可以参考这个思路实现两个数字的相加功能。
//另外还有一个需要注意的问题：如果输入的数字中有负数，我们应该怎么去处理？