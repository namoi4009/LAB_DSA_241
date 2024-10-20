#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int x, y;
    int dir;
    Node(int i, int j) {
        x = i;
        y = j;
        dir = 0;
    }
};

bool check(int x, int y, int fx, int fy) {
    return ((x - 1 == fx && y == fy) || 
            (x + 1 == fx && y == fy) || 
            (x == fx && y - 1 == fy) || 
            (x == fx && y + 1 == fy));
}

bool canEatFood(int maze[5][5], int fx, int fy){
    /*TODO*/
    stack<Node*> travel;
    Node* newNode = new Node(0, 0);
    travel.push(newNode);
    int pDirect = -2;
    while (!travel.empty()) {
        Node* curr = travel.top();
        if (curr->dir == 0) { // try up direction
            curr->dir++;
            if (!curr->y || curr->dir - 1 == pDirect) continue;
            int newY = curr->y - 1;
            if (check(curr->x, newY, fx, fy)) return true;
            Node* next = new Node(curr->x, newY);
            travel.push(next);
            pDirect = 2;
        } else if (curr->dir == 1) { // try left direction
            curr->dir++;
            if (!curr->x || curr->dir - 1 == pDirect) continue;
            int newX = curr->x - 1;
            if (check(newX, curr->y, fx, fy)) return true;
            Node* next = new Node(newX, curr->y);
            travel.push(next);
            pDirect = 3;
        } else if (curr->dir == 2) { // try down direction
            curr->dir++;
            if (curr->y == 5 || curr->dir - 1 == pDirect) continue;
            int newY = curr->y + 1;
            if (check(curr->x, newY, fx, fy)) return true;
            Node* next = new Node(curr->x, newY);
            travel.push(next);
            pDirect = 0;
        } else if (curr->dir == 3) { // try right direction
            curr->dir++;
            if (curr->x == 5 || curr->dir - 1 == pDirect) continue;
            int newX = curr->x + 1;
            if (check(newX, curr->y, fx, fy)) return true;
            Node* next = new Node(newX, curr->y);
            travel.push(next);
            pDirect = 1;
        } else { // dead-end
            travel.pop();
        }
    }
    return false;
}

int main() {
    // Maze matrix
    int maze[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 0 },
        { 0, 1, 0, 1, 1 },
        { 0, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 0 }
    };

    // Food coordinates
    int fx = 2, fy = 3;

    cout << canEatFood(maze, fx, fy);
    return 0;
}