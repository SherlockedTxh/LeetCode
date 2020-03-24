#include <string>
#include <vector>
using namespace std;

// dp[i][j] 表示s[i]到s[j]为回文
// dp[i][j] = dp[i+1][j-1] && s[i]==s[j]
// 递推公式中我们可以看到，我们首先知道了 i+1 才会知道 i ，所以我们只需要倒着遍历就行了。
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

// 优化空间
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string str("");
        if(len == 0 || len == 1)
            return s;
        vector<bool> dp(len);
        for(int i = len - 1; i >= 0; i--){
            for(int j = len - 1; j >= i; j--){
                dp[j] = s[i] == s[j] && (j - i < 2 || dp[j - 1]); //j-i<2即1一个字符或者两个相同字符的情况
                if(dp[j] && j - i + 1 > str.size()){
                    str = s.substr(i, j - i + 1);
                }
            }
        }
        return str;
    }
};

// 中心扩展法
// 我们知道回文串一定是对称的，所以我们可以每次循环选择一个中心，进行左右扩展，判断左右字符是否相等即可。
// 由于存在奇数的字符串和偶数的字符串，所以我们需要从一个字符开始扩展，或者从两个字符之间开始扩展，所以总共有 n+n-1 个中心。
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string str("");
        if(size == 0 || size == 1)
            return s;
        int start = 0, end = 0, len;
        for(int i = 0; i < size; i++){
            int len1 = expandAroundCenter(s, i, i); // 奇数字符串
            int len2 = expandAroundCenter(s, i, i + 1); // 偶数字符串
            len = max(len1, len2);
            if(len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};
