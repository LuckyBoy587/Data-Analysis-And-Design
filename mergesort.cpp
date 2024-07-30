#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left;
    int rightSize = right - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for (int i = left; i < mid; i++) {
        leftArr[i - left] = arr[i];
    }

    for (int i = mid; i < right; i++) {
        rightArr[i - mid] = arr[i];
    }

    int i = 0, j = 0;
    for (int index = left; index < right; index++) {
        if (i == leftSize)
            arr[index] = rightArr[j++];
        else if (j == rightSize)
            arr[index] = leftArr[i++];
        else if (leftArr[i] <= rightArr[j])
            arr[index] = leftArr[i++];
        else
            arr[index] = rightArr[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (right - left == 1)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 45, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size);
    for (int n : arr) {
        cout << n << ' ';
    }
}

// Approach - Divide & Conquer
// Time Complexity = O(nlog(n))
// Space Complexity = O(n) 