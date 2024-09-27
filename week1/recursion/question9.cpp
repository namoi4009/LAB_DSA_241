#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int findLCM(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    cout << findLCM(10, 102);
    return 0;
}