#include <iostream>

using namespace std;

int foldShift(long long key, int addressSize) {
    long long divisor = 1;
    for (int i = 0; i < addressSize; i++) {
        divisor *= 10;
    }

    long long unit = 1;
    long long tempKey = key;
    while (tempKey > 0) {
        unit *= 10;
        tempKey /= 10;
    }

    int hashValue = 0;
    while (key > 0) {
        unit /= divisor;
        if (unit > 0) {
            hashValue += key / unit;
            key %= unit;
        } else {
            hashValue += key;
            break;
        }
        hashValue %= divisor;
    }

    return hashValue;
}

int rotation(long long key, int addressSize) {
    long long temp = key;
    long long multiplier = 1;
    while (temp >= 10) {
        temp /= 10;
        multiplier *= 10;
    }

    temp = key % 10;
    key /= 10;
    key = key + temp * multiplier;

    return foldShift(key, addressSize);
}

int main() {
    cout << foldShift(1234567892, 3);
    return 0;
}