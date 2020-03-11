#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// dp[i][j] 代表word1前i个字符转换成word2前j个字符需要最少步数
// 当 word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]；
// 当 word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
// 其中，dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作。
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1(word1.size()), len2(word2.size());
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        //初始化
        for(int i = 1; i <= len1; i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= len2; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= len1; i ++){
            for(int j = 1; j <= len2; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};