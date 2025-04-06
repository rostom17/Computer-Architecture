#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include <chrono>  // For timing

using namespace std;
using namespace std::chrono;

// Quick Sort Partition
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort Function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    const int SIZE = 100000000; // 100 million
    vector<int> arr(SIZE);

    // Generate random integers
    srand(time(nullptr));
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand();
    }

    // Time the quicksort
    cout << "Sorting started...\n";
    auto start = high_resolution_clock::now();

    quickSort(arr, 0, SIZE - 1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Sorting completed.\n";
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
