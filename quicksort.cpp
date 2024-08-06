#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (high + low) / 2;
    int pivot = arr[mid];
    int first = low, last = high;

    while (first < last) {
        while (arr[first] < pivot) first++;
        while (arr[last] > pivot) last--;

        if (first <= last) {
            int temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;

            first++;
            last--;
        }
    }

    quickSort(arr, low, last);
    quickSort(arr, first, high);
}

int main() {
    int arr[] = {6,1,4,6,2,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printArr(arr, size);
    return 0;
}
