#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int secondsToBeRotten(vector<vector<int>>& grid) {
    int n = grid.size();    // rows
    int m = grid[0].size(); // columns
    queue<pair<int, int>> rotten;
    int freshCount = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) { // rotten
                rotten.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }
    if (freshCount == 0) return 0;

    vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    while (!rotten.empty()) {
        int len = rotten.size();
        bool isRotten = false;

        for (int i = 0; i < len; i++) {
            auto [x, y] = rotten.front();
            rotten.pop();

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX > 0 && newX < n && newY > 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    freshCount--;
                    rotten.push({newX, newY});
                    isRotten = true;
                }
            }
        }
        if (isRotten) time++;
    }
    return freshCount == 0 ? time : -1;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << secondsToBeRotten(grid);
    return 0;
}