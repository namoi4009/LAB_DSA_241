#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void interleaveQueue(queue<int>& q){
    int mid = (q.size() / 2) - 1;
}

int main() {
    int a[] = {1, 2, 3, 4};
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