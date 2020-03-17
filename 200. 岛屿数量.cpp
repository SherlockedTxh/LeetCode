#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// DFS 写下来居然没bug一遍过了哈哈开心
class Solution {
private:
    vector<vector<bool>> visited;
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int column = grid[0].size();
        visited = vector(row, vector<bool>(column));
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < column; j ++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(i, j, grid);
                    ans ++;
                }
            }
        }
        return ans;
    }
    void dfs(int x, int y, vector<vector<char>>& grid){
        int new_x, new_y;
        int row = grid.size(), column = grid[0].size();
        for(auto dir : direction){
            new_x = x + dir[0];
            new_y = y + dir[1];
            if(new_x >= 0 && new_x < row && new_y >= 0 && new_y < column){
                if(!visited[new_x][new_y] && grid[new_x][new_y] == '1'){
                    visited[new_x][new_y] = true;
                    dfs(new_x, new_y, grid);
                }
            }
        }
        return;
    }
};