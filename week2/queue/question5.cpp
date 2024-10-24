#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int secondsToBeRotten(vector<vector<int>>& grid) {
    
    
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