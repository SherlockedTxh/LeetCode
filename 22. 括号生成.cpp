#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left(0), right(0); //左右括号数
        string str;
        vector<string> ans;
        f(n * 2, n, 0, 0, str, ans);
        return ans;
    }
    void f(int pos, int n, int left, int right, string& str, vector<string>& ans){
        if(pos == 0){
            if(left == right){
                ans.push_back(str);
            }
            return;
        }
        if(left < n){
            str.push_back('(');
            f(pos - 1, n, left + 1, right, str, ans);
            str.pop_back(); //注意这里要删掉str新加的元素
        }
        if(left > right){
            str.push_back(')');
            f(pos - 1, n, left, right + 1, str, ans);
            str.pop_back();
        }
        return;
    }
};
