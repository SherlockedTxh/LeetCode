#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

//一开始看错题目。。没看到一次只能走一步或者两步。下面是不限制步数的方法：
//隔板法
//组合数公式C(n, k) = C(n-1, k-1) + C(n-1, k)
class Solution {
public:
    int climbStairs(int n) {
        vector<vector<int>> dp(n + 1,vector<int>(n + 1));
        int ans = 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        for(int i = 1; i <= n; i ++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j < i; j++){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        for(int i = 0; i < n; i ++){
            ans += dp[n - 1][i];
        }
        return ans;
    }
};
