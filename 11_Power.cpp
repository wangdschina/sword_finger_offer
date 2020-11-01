//概述：数值的整数次方
//题目：实现函数 double Power（double base, int exponent），求 base 的exponent次方。
//不得使用库函数，同时不需要考虑大数问题。

//解题：分解求解。例如求32次方，可以先求16次方，然后求得结果相乘。
//时间复杂度：O(logn)


//it's me.
double Power(double base, int exponent)
{
    
    if (EqualFloat(base, 0.0))
        return 0;

    if (exponent == 0)
        return 1;

     unsigned int absExp = exponent < 0 ? -exponent : exponent;
     double ret = PowerCore(base, absExp);
     return exponent < 0 ? (1 / ret) : (ret);
}

bool EqualFloat(double a, double b)
{
    static const double Exp = 0.0000001f;
    if ((a - b) <= Exp && (a - b) >= -Exp)
        return true;
    else 
        return false;
}

double PowerCore(double base, unsigned int exp)
{
    double retsult = 0;
    if (exp >= 2)
    {
        double temp = PowerCore(base, exp / 2);
        return exp % 2 ? (temp * temp * base) : (temp * temp);
    }
    
    return base;
}

//*************************************************************************//
//method
bool g_InvalidInput = false;
double Power(double base, int exponent)
{
    g_InvalidInput = false;
    if (EqualFloat(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;
    
    return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 0;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1); //采用移位的操作更加高效
    result *= result;
    if (exponent & 0x1) //高效的做法
        result *= base;

    return result;
}
//*************************************************************************//
