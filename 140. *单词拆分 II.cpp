#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;

// 回溯 超时
class Solution {
private:
    vector<int> memo;
    vector<string> ans;
public:
    bool helper(string s, string tmp, unordered_set<string> hashset, int start){
        int len = s.size();
        if(start == len){ //注意是左闭右开
            ans.push_back(tmp.substr(0, tmp.size() - 1));
            return true;
        }
        if(memo[start] == 0) return false;
        for(int end = start + 1; end <= len; end ++){
            if(hashset.count(s.substr(start, end - start)) && helper(s, tmp + s.substr(start, end - start) + " ", hashset, end)){
                memo[start] = 1;
            }
        }
        // memo[start] = 0;
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), -1);
        unordered_set<string> hashset = unordered_set<string>(wordDict.begin(), wordDict.end());       
        string tmp = "";
        helper(s, tmp, hashset, 0);
        return ans;
    }
};

// 记忆化回溯
class Solution {
private:
    unordered_map<int, vector<string>> map; // key是当前考虑字符串的开始下标，value包括所有从该下标开始的所有可行句子
public:
    vector<string> helper(string s, unordered_set<string> hashset, int start){
        int len = s.size();
        if(map.count(start)){
            return map[start];
        }
        vector<string> ans;
        if(start == len){
            ans.push_back("");
        }
        for(int end = start + 1; end <= len; end ++){
            if(hashset.count(s.substr(start, end - start))){
                vector<string> rest = helper(s, hashset, end);
                for(string each : rest){
                    ans.push_back(s.substr(start, end - start) + (each == "" ? "" : " ") + each);
                }
            }
        }
        map[start] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset = unordered_set<string>(wordDict.begin(), wordDict.end());       
        return helper(s, hashset, 0);
    }
};

// 动态规划
// 定义 vector<vector<string>> dp(s.size() + 1, vector<string>())
// 假设从开始到第 i - 1 个字符是与字典匹配的一个词，那么第 i 个字符是一个新词的开头字母
// 把这个词添加到 dp[i] 中
// 从第 i 个字符如果再匹配到一个词，把 dp[i] 中的每个词加个空格再加上新词，添加到后面的 dp[j] 中
// dp[i] 表示第 i 个字符前，所有的拆分情况
class Solution {
private:
    unordered_set<string> hashset;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        if(!wordBreak139(s, wordDict)) return {};
        vector<vector<string>> dp(s.size() + 1, vector<string>());;
        dp[0].push_back("");
        for(int i = 0; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(dp[j].size() > 0 && hashset.count(s.substr(j, i - j))){
                    for(string str : dp[j]){
                        dp[i].push_back(str + (str == "" ? "" : " ") + s.substr(j, i - j));
                    }
                }
            }
        }
        return dp[len];
    }

    // 先判断是否可拆分，因为直接做的话测试用例31很容易爆内存
    bool wordBreak139(string s, vector<string>& wordDict) {
        hashset = unordered_set<string>(wordDict.begin(), wordDict.end());       
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