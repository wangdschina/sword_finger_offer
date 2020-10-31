//概述：二进制中1的个数
//题目：请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
//例如把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

//解题思路：
//时间复杂度：


//方法1：用 1 左移的方式跟输入的数做 位与 操作
//32位的整数需要循环32次
int NumberOf1InBinary(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            ++count;
        flag = flag << 1;
    }

    return count;
}

//方法2：把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。
//那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作。
//整数的二进制中有几个1就做几次循环。
int NumberOf1(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = n & (n -1);
    }
    
    return count;
}


/////////////////////////////////////////////////////////////////////////
//相关题目：
//1.用一条语句判断一个整数是不是2的整数次方。一个整数如果是2的整数次方，那么它的二进制表示中有且只有一位是1，而其他所有位都是0。
//  根据前面的分析，把这个整数减去1之后再和它自己做与运算，这个整数中唯一的1就会变成0。
//2.输入两个整数m和n，计算需要改变m的二进制表示中的多少位才能得到 n。
//  比如 10 的二进制表示为 1010，13 的二进制表示为1101，需要改变1010中的3位才能得到1101。
//  我们可以分为两步解决这个问题：第一步求这两个数的异或，第二步统计异或结果中1的位数。
/////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////
//举一反三：
//把一个整数减去 1 之后再和原来的整数做位与运算，得到的结果相当于是把整数的二进制表示中的最右边一个1变成0。
//很多二进制的问题都可以用这个思路解决。
/////////////////////////////////////////////////////////////////////////