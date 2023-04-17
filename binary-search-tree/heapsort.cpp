#include <iostream>

using namespace std;

const int HEAP_LENGTH = 1001;
int heap_size;

int arr[HEAP_LENGTH];

void max_heapify(int idx)
{
    int cur = arr[idx];

    int largest = idx;
    if (2 * idx <= heap_size && arr[2 * idx] > arr[largest])
    {
        largest = 2 * idx;
    }
    if (2 * idx + 1 <= heap_size && arr[2 * idx + 1] > arr[largest])
    {
        largest = 2 * idx + 1;
    }

    if (largest == idx)
        return;

    int tmp = arr[largest];
    arr[largest] = arr[idx];
    arr[idx] = tmp;

    max_heapify(largest);
}

void build_max_heap()
{
    for (int i = heap_size / 2; i >= 1; i++)
        max_heapify(i);
}

int main()
{
    cin >> heap_size;
}