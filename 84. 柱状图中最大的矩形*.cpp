#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 栈：遍历数组，当a[i-1]<=a[i]时压栈，当a[i-1]>a[i]时，开始弹栈，直到a[stack[top]]<a[i]
// 以弹出元素为高的最大矩形面积为：(i-stack[top-1]-1)*a[stack[top]]
// 到达数组尾部时，把栈中剩余元素全部弹出，以弹出元素为高的最大矩形面积为：(a.length-stack[top-1]-1)*a[stack[top]]
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};