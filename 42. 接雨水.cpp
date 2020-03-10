#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int max_height = 0, ans = 0;
        vector<int> dp; //代表左侧最高点
        for(int i = 0; i < height.size(); i ++){
            max_height = max(height[i], max_height);
            dp.push_back(max_height);
        }
        max_height = 0;
        for(int i = height.size() - 1; i >= 0; i --){
            max_height = max(height[i], max_height);
            ans += min(max_height, dp[i]) - height[i];
        }
        return ans;
    }
};