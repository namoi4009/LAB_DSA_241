#include <iostream>
#include <stack>

using namespace std;

bool isValidParentheses (string s){
    /*TODO*/
    stack<char> store;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (store.empty()) {
            store.push(s[i]);
        } else {
            if ((store.top() == '[' && s[i] == ']') ||
                (store.top() == '(' && s[i] == ')') ||
                (store.top() == '{' && s[i] == '}')) {
                store.pop();
            } else 
                store.push(s[i]);
        }
    }
    return store.empty();
}

int main() {
    cout << isValidParentheses("[]") << endl;
    cout << isValidParentheses("[]()") << endl;
    cout << isValidParentheses("[)") << endl;
    return 0;
}