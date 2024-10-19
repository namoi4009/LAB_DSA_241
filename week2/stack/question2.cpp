#include <iostream>
#include <stack>

using namespace std;

int baseballScore(string ops){
    /*TODO*/
    stack<int> score;
    int n = ops.length(), sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        if (ops[i] == '+') {
            temp = score.top();
            score.pop();
            int newScore = 0;
            newScore = temp + score.top();
            score.push(temp);
            score.push(newScore);
            sum += newScore;
        } else if (ops[i] == 'C') {
            sum -= score.top();
            score.pop();
        } else if (ops[i] == 'D') {
            temp = score.top();
            score.push(temp * 2);
            sum += temp * 2;
        } else {
            sum += ops[i] - '0';
            score.push(ops[i] - '0');
        }
    }
    return sum;
}

int main() {
    cout << baseballScore("52CD+");
    cout << baseballScore("524CD9++");
    return 0;
}