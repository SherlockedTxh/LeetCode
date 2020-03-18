#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// dp[i][j] 表示以[i][j]为右下角的正方形的边长
// dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int column = matrix[0].size();
        vector<vector<int>> dp = vector(row + 1, vector<int>(column + 1)); // 这里加1，可以省去初始化第一行和第一列
        int maxlen = 0;
        for(int i = 1; i <= row; i ++){
            for(int j = 1; j <= column; j ++){
                if(matrix[i - 1][j - 1] == '1'){
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    maxlen =max(dp[i][j], maxlen);
                }
            }
        }
        return maxlen * maxlen;
    }
};

// 优化空间 dp变为一维数组
在前面的动态规划解法中，计算第i行（row）的 dp 方法中，我们只使用了上一个元素和第i - 1行，因此我们不需要二维 dp 矩阵，因为一维 dp 足以满足此要求。
我们扫描一行原始矩阵元素时，我们根据公式：dp[j] = min(dp[j], dp[j - 1], pre) + 1 更新数组 dp，其中 prev 指的是 dp[j−1]，对于每一行，我们重复相同过程并在 dp 矩阵中更新元素。
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int column = matrix[0].size();
        vector<int> dp = vector<int>(column + 1);
        int maxlen = 0, pre = 0;
        for(int i = 1; i <= row; i ++){
            for(int j = 1; j <= column; j ++){
                int tmp = dp[j];
                if(matrix[i - 1][j - 1] == '1'){
                    dp[j] = min(dp[j], min(dp[j - 1], pre)) + 1;
                    maxlen = max(dp[j], maxlen);
                }
                else{
                    dp[j] = 0;
                }
                pre = tmp;
            }
        }
        return maxlen * maxlen;
    }
};