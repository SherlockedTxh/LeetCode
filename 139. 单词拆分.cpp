#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
using namespace std;

// 方法一：记忆化回溯
class Solution {
private:
    vector<int> memo;
public:
    bool helper(string s, unordered_set<string> hashset, int start){
        int len = s.size();
        if(start == len) return true; //注意是左闭右开
        if(memo[start] == 1) return true;
        else if(memo[start] == 0) return false;
        for(int end = start + 1; end <= len; end ++){
            if(hashset.count(s.substr(start, end - start)) && helper(s, hashset, end)){
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), -1);
        unordered_set<string> hashset = unordered_set<string>(wordDict.begin(), wordDict.end());       
        return helper(s, hashset, 0);
    }
};

// 方法二：动态规划
// 动态规划方法的递推公式可以简略的表示为：
// dp[i] = ( dp[i-1] && contains(subStr(i-1,i))  )
//         || (  dp[i-2] && contains(subStr(i-2,i))  )
//         || (  dp[i-3] && contains(subStr(i-3,i))  ) 
//         || ...
// 注意dp长度为len + 1，注意下标
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset = unordered_set<string>(wordDict.begin(), wordDict.end());       
        int len = s.size();
        vector<bool> dp = vector<bool>(len + 1);
        dp[0] = true;
        for(int i = 1; i <= len; i ++){
            for(int j = 0; j < i; j ++){
                if(dp[j] && hashset.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};