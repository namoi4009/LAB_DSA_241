#include <iostream>

using namespace std;

void printHailstone(int number)
{
    /*  
     * STUDENT ANSWER
     */
    if (number == 1) {
        cout << number;
        return;
    }

    cout << number << " ";
    if (number % 2 == 0) printHailstone(number / 2);
    if (number % 2 == 1) printHailstone((3 * number) + 1);
}

int main() {
    printHailstone(32);
    return 0;
}