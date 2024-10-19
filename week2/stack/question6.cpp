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

bool canEatFood(int maze[5][5], int fx, int fy){
    /*TODO*/
    stack<Node*> travel;
    Node* newNode = new Node(0, 0);
    travel.push(newNode);
    int pDirect = -1;
    while (!travel.empty()) {
        Node* curr = travel.top();
        if (curr->dir == 0) { // try up direction
            curr->dir++;
            if (!curr->y && curr->dir != pDirect) continue;
            int newY = curr->y--;
            if (curr->x == fx && curr->y == fy) return true;
            Node* next = new Node(curr->x, newY);
            travel.push(next);
        } else if (curr->dir == 1) { // try left direction
            curr->dir++;
            if (!curr->x && curr->dir != pDirect) continue;
            int newX = curr->x--;
            if (newX == fx && curr->y == fy) return true;
            Node* next = 
        } else if (curr->dir == 2) { // try down direction
            curr->dir++;
            if (curr->y == 5 && curr->dir != pDirect) continue;
        } else if (curr->dir == 3) { // try right direction
            curr->dir++;
            if (curr->x == 5 && curr->dir != pDirect) continue;
        } else { // dead-end
            travel.pop();
        }
    }
}

int main() {
    // Maze matrix
    int maze[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 1, 0 }
    };

    // Food coordinates
    int fx = 1, fy = 4;

    cout << canEatFood(maze, fx, fy);
    return 0;
}