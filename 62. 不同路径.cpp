#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

//dp思路:到达右下角的路径数 = 到达右下角上面一格的路径数 + 到达右下角左边一格的路径数
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector(m, vector<int>(n));
        if(m == 1 || n == 1) return 1;
        for(int i = 0; i < m; i ++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i ++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};