#include <iostream>

using namespace std;
 
void printArray(int n) {
    if (n == 0) {
        cout << n;
    } else {
        printArray(n - 1);
        cout << ", " << n;
    }
}

int main() {
    int n = 10;
    printArray(n);
    return 0;
}