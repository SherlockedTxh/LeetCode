#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 动态规划
// 1、s[i] = 0时，若s[i-1]是1或2，则dp[i] = dp[i-2]，否则解码出错
// 2、else if s[i-1]是1，dp[i] = dp[i-1] + dp[i-2]
// 3、else if s[i-1]是2，且s[i]小于7，dp[i] = dp[i-1] + dp[i-2]
// 4、else dp[i] = dp[i-1]
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len == 0) return 0;
        if(s[0] == '0') return 0;
        int pre = 1, cur = 1;
        for(int i = 1; i < len; i++){
            int tmp = cur;
            if(s[i] == '0'){
                if(s[i - 1] == '1' || s[i - 1] == '2'){
                    cur = pre;
                }
                else return 0;
            }
            else if(s[i - 1] == '1'){
                cur = cur + pre;
            }
            else if(s[i - 1] == '2'){
                if(s[i] >= '1' && s[i] <= '6'){
                    cur = cur + pre;
                }
            }
            pre = tmp;
        }
        return cur;
    }
};