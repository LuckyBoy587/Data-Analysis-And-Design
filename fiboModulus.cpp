#include <iostream>

using namespace std;

int getNextFibElement() {
    static int n1 = 1, n2 = 1;
    int next = n1 + n2;
    n1 = n2;
    n2 = next;
    return next;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    if (n1 == 1) {
        cout << n2;
        return 0;
    }
    
    int count = 2;
    while (n2 > 0) {
        int next = getNextFibElement();
        if (next % n1 == 0) {
            n2--;
        }
        count++;
    }

    cout << count;
}