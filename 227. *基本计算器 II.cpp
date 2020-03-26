#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <set>
#include <ctype.h>
using namespace std;

// 栈
// sign存储当前扫描到的字符前一个符号
// https://leetcode-cn.com/problems/basic-calculator-ii/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-/
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0; // 记录数字
        char sign = '+'; // 记录符号
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            // 如果是数字，连续读取
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            if((!isdigit(c) && c != ' ') || i == s.size() - 1){
                switch (sign){
                    int pre;
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    // 乘除法只要拿出前一个数字做对应运算即可
                    case '*':
                        pre = st.top();
                        st.pop();
                        st.push(pre * num);
                        break;
                    case '/':
                        pre = st.top();
                        st.pop();
                        st.push(pre / num);
                        break;
                }
                // 更新符号为当前符号，数字清零
                sign = c;
                num = 0;
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};