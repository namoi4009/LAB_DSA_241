#include <iostream>

using namespace std;

long int midSquare(long int seed)
{
    int sq = seed * seed;
    int temp = sq / 100;
    return temp % 10000;
}

long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}

long int digitExtraction(long int seed, int* extractDigits, int size)
{
    int digits[20];
    int numDigits = 0;
    long int tempSeed = seed;

    while (tempSeed > 0) {
        tempSeed /= 10;
        numDigits++;
    }
    tempSeed = seed;
    for (int i = numDigits - 1; i >= 0; i--) {
        digits[i] = tempSeed % 10;
        tempSeed /= 10;
    }

    long int hashValue = 0;
    for (int i = 0; i < size; i++) {
        int idx = extractDigits[i];
        if (idx >= 0 && idx < numDigits) {
            hashValue = hashValue * 10 + digits[idx];
        }
    }
    return hashValue;
}

int main() {
    int a[]={1,2,5};
    cout << digitExtraction(122443,a,3);
    return 0;
}