#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//方法一 栈
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> tmp;
        int len = s.size(), ans(0);
        if(len == 0) return 0;
        tmp.push(-1);
        for(int i = 0; i < len; i ++){
            if(s[i] == '('){
                tmp.push(i);
            }
            else{
                tmp.pop();
                if(s.empty()){
                    tmp.push(i);
                }
                else{
                    ans = max(ans, i - tmp.top());
                }
            }
        }
        return ans;
    }
};

//方法二 动态规划
dp[i]=下表为i的字符结尾的最长有效字符的长度
1. s[i]=')' and s[i-1]='(',也就是字符串形如"...()":
    dp[i]=fp[i-2]+2
2. s[i]=')' and s[i-1]=')'，也就是字符串形如"...))":
    如果s[i-dp[i-1]-1]='(':
        dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2
