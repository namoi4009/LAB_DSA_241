#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void interleaveQueue(queue<int>& q){
    int halfSize = q.size() / 2;
    queue<int> f;
    for (int i = 0; i < halfSize; i++) {
        f.push(q.front()); q.pop();
    }
    queue<int> b;
    while (!q.empty()) {
        b.push(q.front()); q.pop();
    }
    for (int i = 0; i < halfSize; i++) {
        q.push(f.front()); f.pop();
        q.push(b.front()); b.pop();
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    queue<int> q;
    int len = sizeof(a)/sizeof(int);
    for (int i = 0; i < len; i++)
        q.push(a[i]);

    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}