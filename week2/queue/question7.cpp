#include <iostream>
#include <queue>

using namespace std;

long long toInteger(string number) {
    long long res = 0;
    for (int i = 0; i < number.size(); i++) {
        res = (res * 10) + (number[i] - '0');
    }
    return res;
}

long long nthNiceNumber(int n) {
    queue<string> nice;
    nice.push("2");
    nice.push("5");

    string niceNumber = "";

    for (int i = 0; i < n; i++) {
        niceNumber = nice.front();
        nice.pop();

        nice.push(niceNumber + "2");
        nice.push(niceNumber + "5");
    }

    return toInteger(niceNumber);
}

int main() {
    cout << nthNiceNumber(10000) << endl;
    return 0;
}