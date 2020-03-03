#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string str("");
        if(len == 0 || len == 1)
            return s;
        vector<vector<bool>> dp(len, vector<bool>(len));
        for(int i = len - 1; i >= 0; i--){
            for(int j = i; j < len; j ++){
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]); //j-i<2即1一个字符或者两个相同字符的情况
                if(dp[i][j] && j - i + 1 > str.size()){
                    str = s.substr(i, j - i + 1);
                }
            }
        }
        return str;
    }
};