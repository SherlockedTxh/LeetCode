#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// DFS：
// 我们需要先找出不合法的左括号个数和右括号个数
// 利用dfs不断删除"（"或者"）"，直到不合法个数为0
// 检验删除后的括号串是否合法。
class Solution {
private:
    vector<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        // 寻找不合法半边括号的个数,
        int left = 0, right = 0;
        for(char c : s){
            if(c == '('){
                left++;
            }
            if(c == ')'){
                if(left > 0) left--;
                else right ++;
            }
        }
        // 深度优先遍历，寻找题解
        // left与right为需要删除的数量
        dfs(s, 0, left, right);
        
        return ans;
    }

    void dfs(string str, int pos, int left, int right){
        if(left == 0 && right == 0){
            if(check(str)){
                ans.push_back(str);
            }
            return;
        }
        for(int i = pos; i < str.size(); i++){
            // 去重，该符号与前一个符号相同，那么无论删除哪个都是一样的
            if(i - 1 >= pos && str[i] == str[i - 1]) continue;
            if(left > 0 && str[i] == '('){
                dfs(str.substr(0,i) + str.substr(i + 1, str.size() - i - 1), i, left - 1, right);
            }
            if(right > 0 && str[i] == ')'){
                dfs(str.substr(0,i) + str.substr(i + 1, str.size() - i - 1), i, left, right - 1);
            }
        }
    }

    // 检验合法性
    bool check(string str){
        int cnt = 0;
        for(char c : str){
            if(c == '('){
                cnt++;
            }
            if(c == ')'){
                cnt --;
                if(cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};