#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;

// 栈
// Note: c++负数除法向上取整，比如：10/(-4) = -2，python是向下取整
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for(string str : tokens){
            int a, b;
            if(str == "+" or str == "-" or str == "*" or str == "/"){
                a = mystack.top();
                mystack.pop();
                b = mystack.top();
                mystack.pop();
                if(str == "+") mystack.push(a + b);
                if(str == "-") mystack.push(b - a);
                if(str == "*") mystack.push(a * b);
                if(str == "/") mystack.push(b / a);
            }
            else{
                mystack.push(stoi(str));
            }
        }
        return mystack.top();
    }
};
