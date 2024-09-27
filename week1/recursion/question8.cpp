#include <iostream>

using namespace std;

int powerTen(int n) {
    if (n == 0) return 1;
    return 10 * powerTen(n - 1);
}

int myArrayToInt(char *str, int n) 
{ 
    /*  
     * STUDENT ANSWER
     */
    if (n == 0) return 0;
    int unit = str[0] - '0';
    return unit * powerTen(n - 1) + myArrayToInt(str + 1, n - 1);
}

int main() { 
    char str[] = "2020";
    printf("%d", myArrayToInt(str, 4));
    return 0;
}