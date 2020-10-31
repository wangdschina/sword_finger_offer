//概述：快排

int Partition(int data[], int length, int start, int end); //definition in Partition.cpp

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;
    
    int index = Partition(data, length, start, end);
    if (index > start)
        QuickSort(data, length, start, index - 1);
    if (index < end)
        QuickSort(data, length, index + 1, end);
}