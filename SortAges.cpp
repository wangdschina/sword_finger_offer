//概述：实现时间复杂度为 O(n) 的排序。
//解题：借用额外空间，先统计不同年龄出现的次数。

void SortAges(int ages[], int length)
{
    if (nullptr == ages || length <= 0)
        throw std::exception("Invalid Input");

    const int oldestAge = 99;
    int numberOfAge[oldestAge + 1];
    for (int i = 0; i <= oldestAge; i++)
        numberOfAge[i] = 0;

    //统计年龄分布，不同年龄的次数
    for (int i = 0; i < length; i++)
    {
        int age = ages[i];
        if (age < 0 && age > oldestAge)
            throw std::exception("age out of range.");
        ++numberOfAge[age];
    }

    int index = 0;
    for (int i = 0; i < oldestAge; i++)
    {
        for (int j = 0; j < numberOfAge[i]; j++)
            ages[index++] = i;
    }
    
        
}