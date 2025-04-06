#include <iostream>
#include <vector>
#include <cstdlib>      // For rand()
#include <ctime>        // For time()
#include <chrono>       // For timing

using namespace std;
using namespace std::chrono;

// Merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> L(leftSize);
    vector<int> R(rightSize);

    for (int i = 0; i < leftSize; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < rightSize; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < leftSize) arr[k++] = L[i++];
    while (j < rightSize) arr[k++] = R[j++];
}

// Recursive Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int SIZE = 100000000; // 100 million
    vector<int> arr(SIZE);

    // Seed and fill array with random numbers
    srand(time(nullptr));
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand();
    }

    cout << "Sorting started...\n";
    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, SIZE - 1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Sorting completed.\n";
    cout << "Time taken: " << duration.count() << " miliseconds" << endl;

    return 0;
}
