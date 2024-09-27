#include <iostream>
#include <string.h>

using namespace std;

// do geese see god -> 0 

// Helper function
bool isPalindrome(string str) {
    if (str.length() <= 1) {
        return true;
    }

    if (str[0] == ' ') {
        return isPalindrome(str.substr(1, str.length() - 1));
    } else if (str[str.length() - 1] == ' ') {
        return isPalindrome(str.substr(0, str.length() - 1));
    } else {
        return str[0] == str[str.length() - 1] && isPalindrome(str.substr(1, str.length() - 2));
    }

    return true;
}

int main() {
    cout << isPalindrome("meme");
    return 0;
}