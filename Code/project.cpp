#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <omp.h>

using namespace std;
using namespace std::chrono;

// Shell sort algorithm without parallelism
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Shell sort algorithm with parallelism
void parallelShellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        #pragma omp parallel for schedule(dynamic)
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    const int SIZE = 100000;
    int arr1[SIZE], arr2[SIZE];

    // Initialize worst-case scenario (reverse sorted order)
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = SIZE - i;
        arr2[i] = arr1[i];
    }

    // Measure time for Shell Sort without parallelism
    auto startShellSort = high_resolution_clock::now();
    shellSort(arr1, SIZE);
    auto stopShellSort = high_resolution_clock::now();
    auto durationShellSort = duration_cast<milliseconds>(stopShellSort - startShellSort);
    cout << "Time taken by Shell Sort without parallelism in worst-case scenario: " << durationShellSort.count() << " milliseconds" << endl;

    // Measure time for Shell Sort with parallelism
    auto startParallelShellSort = high_resolution_clock::now();
    parallelShellSort(arr2, SIZE);
    auto stopParallelShellSort = high_resolution_clock::now();
    auto durationParallelShellSort = duration_cast<milliseconds>(stopParallelShellSort - startParallelShellSort);
    cout << "Time taken by Shell Sort with parallelism in worst-case scenario: " << durationParallelShellSort.count() << " milliseconds" << endl;

    return 0;
}