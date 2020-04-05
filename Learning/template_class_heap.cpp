#include <bits/stdc++.h>
using namespace std;
template <typename T>
class MinHeap
{
    T *heap;
    int capacity;
    int size;

public:
    MinHeap(int capacity);
    int get_parent(int i) { return (i - 1) / 2; }
    int get_l_child(int i) { return 2 * i + 1; }
    int get_r_child(int i) { return 2 * i + 2; }
    T get_min();
    T extract_min();
    void insert(int value);
    T delete_(int i);
    void heapify(int i);
};

template <typename T>
MinHeap<T>::MinHeap(int c)
{
    if (c > 1000000)
        throw invalid_argument("Can't initialize Heap for that much size");
    heap = new int[c];
    capacity = c;
    size = 0;
}
template <typename T>
T MinHeap<T>::get_min()
{
    return heap[0];
}
template <typename T>
T MinHeap<T>::extract_min()
{
    T value_to_return = heap[0];
    delete_(0);
    return value_to_return;
}
template <typename T>
void MinHeap<T>::heapify(int i)
{
    int r_child = get_r_child(i);
    int l_child = get_l_child(i);
    int smallest = i;
    if (r_child < size && heap[r_child] < heap[smallest])
        smallest = r_child;
    if (l_child < size && heap[l_child] < heap[smallest])
        smallest = l_child;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}
template <typename T>
void MinHeap<T>::insert(int value)
{
    size++;
    int i = size - 1;
    heap[i] = value;

    while (i >= 0 && heap[get_parent(i)] > heap[i])
    {
        swap(heap[i], heap[get_parent(i)]);
        i = get_parent(i);
    }
}
template <typename T>
T MinHeap<T>::delete_(int i)
{
    int value_to_return = heap[i];
    heap[i] = numeric_limits<int>::max();
    heapify(i);
    size--;
    return value_to_return;
}

int main()
{
    MinHeap<int> h(11);
    h.insert(3);
    h.insert(2);
    h.delete_(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.extract_min() << " ";
    cout << h.get_min() << " ";
    h.delete_(0);
    cout << h.get_min();
    return 0;
}