//概述：部分排序，挑选数组中的一个随机值进行排序，小于该值的放数组左边，大于的放数组右边

int Partition(int data[], int length, int start, int end)
{
    if (nullptr == data || length <= 0 || start < 0 || end >= length)
        throw std::exception("Invalid Param");

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]); //先把随机值放到数组的最后
    int smallIndex = start - 1;
    for (int i = start; i < end; i++)
    {
        if (data[i] < data[end])
        {
            ++smallIndex;
            if (smallIndex != i)
                Swap(&data[smallIndex], &data[i]);
        }
    }
    
    Swap(&data[++smallIndex], &data[end]);
    return smallIndex;
}

int RandomInRange(int start, int end)
{
    return std::rand(start, end);
}

void Swap(int* lhs, int* rhs)
{
    std::swap(lhs, rhs);
}