//概述：斐波那契数列

//题目一：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
//解题：
//时间复杂度：

//No：以下递归的方法有很大的效率问题。
int Fabinacci(int n)
{
    if (n == 0 || n == 1)
        return n;

    return Fabinacci(n - 1) + Fabinacci(n - 2);
}

//Yes： O(n) 的算法
long long Fabinacci(int n)
{
    int a[2] = { 0, 1 };
    if (n < 2)
        return a[n];
    
    typedef long long LLong;
    LLong firstNumber = 0;
    LLong secondNumber = 1;
    LLong fibN = firstNumber + secondNumber;
    for (unsigned i = 2; i <= n; ++i)
    {
        fibN = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = fibN;
    }

    return fibN;
}