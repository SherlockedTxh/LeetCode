#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// Leetcode 84的变体，相当于把每一行以及它上边区域看作一个柱状图，做n次84的过程
class Solution {
public:
    int leetcode84(vector<int>& heights) { //此函数即leetcode 84题的代码
        stack<int> st;
        st.push(-1);
        int ans = 0, tmp = 0;
        for(int i = 0; i < heights.size(); i ++){
            while(st.top() != -1 && heights[st.top()] > heights[i]){
                tmp = st.top();
                st.pop();
                ans = max(ans, (i - st.top() - 1) * heights[tmp]);
            }
            st.push(i);
        }
        while(st.top() != -1){
            tmp = st.top();
            st.pop();
            ans = max(ans, int(heights.size() - 1 - st.top()) * heights[tmp]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int column = matrix[0].size();
        int ans = 0;
        vector<int> dp(column);
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < column; j ++){
                if(matrix[i][j] == '1'){ //是01字符，不是数字...
                    dp[j] ++;
                }
                else {
                    dp[j] = 0;
                }
            }
            ans = max(ans, leetcode84(dp));
        }
        return ans;
    }
};