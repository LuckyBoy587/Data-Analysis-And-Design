#include <iostream>
using namespace std;

struct Person {
    int age;
    float height;

    void display() {
        printf("Age: %d Height: %d\n", age, height);
    }

    float getTypeValue(int type) {
        return type == 1 ? age : height;
    }
};

bool isSorted = true;

void quickSort(Person arr[], int low, int high, int type) {
    if (low >= high) return;
    int mid = (high + low) / 2;
    float pivot = arr[0].getTypeValue(type);

    int first = low, last = high;
    while (first < last) {
        while (arr[first].getTypeValue(type) < pivot) first++;
        while (arr[last].getTypeValue(type) > pivot) last--;

        if (first <= last) {
            if (first < last) isSorted = false;
            Person temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;

            first++;
            last--;
        }
    }

    quickSort(arr, low, last, type);
    quickSort(arr, first, high, type);
}

int main() {
    int size;
    cin >> size;

    Person arr[size];
    for (int i = 0; i < size; i++) {
        if (!(cin >> arr[i].age && cin >> arr[i].height)) {
            cout << "Invalid input";
            return 0;
        }
    }
    int type;
    cin >> type;

    quickSort(arr, 0, size - 1, type);
    if (isSorted) cout << -1;
    else {
        for (Person obj: arr) {
            obj.display();
        }
    }
}