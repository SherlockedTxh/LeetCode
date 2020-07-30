#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 动态规划 这题与 10. 正则表达式匹配 差不多
// DP过程：
// dp[i][j]表示s的前i个是否能被p的前j个匹配
// if p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]；
// if p.charAt(j) == '?' : dp[i][j] = dp[i-1][j-1]；
// if p.charAt(j) == '*'： 因为*可以匹配任意长度字符串，所以dp[k][j-1]中与任意一个为true，那么从k到i的字符串可以用*匹配掉
//     dp[i][j] = dp[1][j-1] | ...| dp[i][j-1] (其中dp[k][j-1] 1<=k<=i)
//     dp[i][j] = dp[i][j - 1] || dp[i - 1][j]
class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s; //在s和p前面加了一个空格，解决了s为空时的特殊情况，避免了繁琐的初始化
        p = " " + p;
        int len1(s.size()), len2(p.size());
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1));
        dp[0][0] = true;
        for(int j = 1; j <= len2 ; j ++){
            // bool tmp = false;
            for(int i = 1; i <= len1; i ++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // tmp = tmp | dp[i][j - 1];
                if(p[j - 1] == '*'){
                    // dp[i][j] = tmp | dp[i][j]; 
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    // 注释的三句是我原来的写法，删掉了这三句加了上面这句，dp[i - 1][j]如果true，那么再加一个s[i]也可以被*匹配
                }
                
            }
        }
        return dp[len1][len2];
    }
};
