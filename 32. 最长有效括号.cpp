#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

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