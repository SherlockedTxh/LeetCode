#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>> dp = vector(row, vector<int>(column));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; i ++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < column; i ++){
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        if(row == 1) return dp[0][column - 1];
        if(column == 1) return dp[row - 1][0];
        for(int i = 1; i < row; i ++){
            for(int j = 1; j < column; j ++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][column - 1];
    }
};
