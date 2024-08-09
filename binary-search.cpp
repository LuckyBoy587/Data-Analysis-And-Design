#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (target < arr[mid]) {
            right = mid - 1;
        } else if (target > arr[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        if (!(cin >> arr[i])) {
            cout << "Invalid input";
            return 0;
        }
    }

    int target;
    cin >> target;  
    cout << binarySearch(arr, size, target);
}