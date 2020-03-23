#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 两步：
// 1、先一个循环构造杨辉三角的边角值
// 2、再利用动态方程dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++){
            ans[i] = vector<int>(i + 1);
            ans[i][0] = 1;
            ans[i][i] = 1;
        }
        for(int i = 1; i < numRows; i++){
            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};