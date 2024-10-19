#include <iostream>
#include <stack>

using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    stack<char> store;
    int n = S.size();
    for (int i = 0; i < n; i++) {
        if (store.empty()) {
            store.push(S[i]);
        } else {
            if (store.top() == S[i])
                store.pop();
            else store.push(S[i]);
        }
    }
    string res = "";
    while (!store.empty()) {
        res = store.top() + res;
        store.pop();
    }
    return res;
}

int main() {
    cout << removeDuplicates("abbaca");
    cout << endl;
    cout << removeDuplicates("aab");
    return 0;
}