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

    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    while (!rotten.empty()) {
        int len = rotten.size();
        bool isRotten = false;

        for (int i = 0; i < len; i++) {
            pair<int, int> pos = rotten.front();
            rotten.pop();

            for (auto dir : directions) {
                int newX = pos.first + dir.first;
                int newY = pos.second + dir.second;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
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
    vector<vector<int>> grid = { {0, 1, 2},
                                 {0, 1, 2},
                                 {2, 1, 1}};
    cout << secondsToBeRotten(grid) << endl;
    return 0;
}