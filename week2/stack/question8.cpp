#include <iostream> 
#include <stack>

using namespace std;

int evaluatePostfix(string expr){
    /*TODO*/
    int n = expr.size();
    stack<int> calc;
    string num = "";
    for (int i = 0; i < n; i++) {
        if (expr[i] >= '0' && expr[i] <= '9') { // the char is number
            num += expr[i];
        } else if (expr[i] == ' ') {
            if (!num.empty()) {
                calc.push(stoi(num));
                num = "";
            } else continue;
        } else {
            int op1 = calc.top();
            calc.pop();
            int op2 = calc.top();
            calc.pop();
            int res = 0;
            if (expr[i] == '+') res = op2 + op1;
            if (expr[i] == '-') res = op2 - op1;
            if (expr[i] == '*') res = op2 * op1;
            if (expr[i] == '/') res = op2 / op1;

            calc.push(res);
        }
    }
    return calc.top();
}

int main() {
    cout << evaluatePostfix("2 3 1 * + 9 -") << endl;
    cout << evaluatePostfix("100 200 + 2 / 5 * 7 +");
    return 0;
}