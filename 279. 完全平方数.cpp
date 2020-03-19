#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// dfs 超时过不了
class Solution {
public:
    int numSquares(int n) {
        return dfs(n);
    }

    int dfs(int n){
        int ans = n;
        for(int i = int(sqrt(n)); i >= 2; i --){
            if(n - i * i == 0){
                return 1;
            }
            else if(n - i * i < 0){
                return INT_MIN;
            }
            else{
                ans = min(dfs(n - i * i) + 1, ans);
            }
        }
        return ans;
    }
};

// 动态规划
// 思路：
// 首先初始化长度为n+1的数组dp，每个位置都为0
// 如果n为0，则结果为0
// 对数组进行遍历，下标为i，每次都将当前数字先更新为最大的结果，即dp[i]=i，比如i=4，最坏结果为4=1+1+1+1即为4个数字
// 动态转移方程为：dp[i] = MIN(dp[i], dp[i - j * j] + 1)，i表示当前数字，j*j表示平方数
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1);
        for(int i = 1; i <= n; i ++){
            dp[i] = i;
            for(int j = 1; i - j * j >= 0; j ++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};