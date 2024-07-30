#include <iostream>
using namespace std;

int reverse(int num) {
    int res = 0;
    while (num > 0) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }

    return res;
}

int square(int num) {
    return num * num;
}

int main() {
    int n;
    cin >> n;

    if (reverse(square(n)) == square(reverse(n))) {
        cout << "Adam Number";
    } else {
        cout << "Not Adam Number";
    }
}