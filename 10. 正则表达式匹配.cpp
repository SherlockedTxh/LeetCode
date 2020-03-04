#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s; //在s和p前面加了一个空格，解决了s为空时的特殊情况，避免了繁琐的初始化
        p = " " + p;
        int len1(s.size()), len2(p.size());
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1));
        dp[0][0] = true;
        for(int i = 1; i <= len1; i ++){
            for(int j = 1; j <= len2 ; j ++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    if(p[j - 2] != s[i - 1] && p[j - 2] != '.'){
                        dp[i][j] = dp[i][j - 2];
                    }
                    else{
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    }
                }
            }
        }
        return dp[len1][len2];
    }
};