#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <set>
#include <ctype.h>
#include <iostream>
#include <iomanip>
using namespace std;

// 二维数组 动态规划 联想：编辑距离
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text2.size(), column = text1.size();
        vector<vector<int>>dp(row+1, vector<int>(column+1));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= column; j++){
                if(text1[j - 1] == text2[i - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[row][column];
    }
};