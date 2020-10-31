//概述：斐波那契数列

//题目一：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
//解题：递归和循环都可以求得。
//时间复杂度：O(n)

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

//Yes：O(logn)
//TODO：使用矩阵的乘法，不够实用


//题目二：一只青蛙一次可以跳上1 级台阶，也可以跳上2 级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//解题：
//1.首先我们考虑最简单的情况。如果只有 1 级台阶，那显然只有一种跳法。
//  如果有2级台阶，那就有两种跳的方法了：一种是分两次跳，每次跳1级；另外一种就是一次跳2级。
//2.接着我们再来讨论一般情况。我们把n级台阶时的跳法看成是n的函数，记为f（n）。
//  当n>2时，第一次跳的时候就有两种不同的选择：一是第一次只跳1级，此时跳法数目等于后面剩下的n-1级台阶的跳法数目，即为f（n-1）；
//  另外一种选择是第一次跳2级，此时跳法数目等于后面剩下的n-2级台阶的跳法数目，即为f（n-2）。
//  因此n级台阶的不同跳法的总数f（n）=f（n-1）+f（n-2）。分析到这里，我们不难看出这实际上就是斐波那契数列了。
long long Forg(int n)
{
    if (n <= 0)
        throw std::exception("Invalid parameters.");
    
    if (n == 1 || n == 2)
        return n;
    
    typedef long long LLong;
    LLong firstNumber = 1;
    LLong secondNumber = 2;
    LLong result = firstNumber + secondNumber;
    for(unsigned i = 3; i <= n; ++i)
    {
        result = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = result;
    }

    return result;
}

//本题扩展：
//在青蛙跳台阶的问题中，如果把条件改成：一只青蛙一次可以跳上 1级台阶，也可以跳上 2 级……它也可以跳上 n 级，
//此时该青蛙跳上一个 n级的台阶总共有多少种跳法？我们用数学归纳法可以证明f（n）=2n-1。