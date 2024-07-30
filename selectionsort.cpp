#include <iostream>
using namespace std;

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionsort(arr, size);

    for (int n : arr) {
        cout << n << " ";
    }
}