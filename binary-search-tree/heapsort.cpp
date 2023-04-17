#include <iostream>

using namespace std;

const int HEAP_LENGTH = 1001;
int heap_size;

int arr[HEAP_LENGTH];

void swap(int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
    return;
}

void max_heapify(int idx)
{
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

    swap(largest, idx);

    max_heapify(largest);
}

void build_max_heap()
{
    for (int i = heap_size / 2; i >= 1; i--)
        max_heapify(i);
}

void heapsort()
{
    build_max_heap();
    while (heap_size > 0)
    {
        swap(1, heap_size);
        heap_size--;
        max_heapify(1);
    }
}

int main()
{
    cin >> heap_size;

    int n_of_items = heap_size;

    for (int i = 1; i <= heap_size; i++)
        cin >> arr[i];

    for (int i = 1; i <= heap_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapsort();
    // build_max_heap();

    for (int i = 1; i <= n_of_items; i++)
        cout << arr[i] << " ";
    cout << endl;
}