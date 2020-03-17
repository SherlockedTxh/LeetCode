#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 动态规划 分别保存以i结尾的最大乘积和最小乘积
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp = vector<int>(len);
        vector<int> negative = vector<int>(len); //最小乘积dp
        dp[0] = nums[0];
        negative[0] = nums[0];
        for(int i = 1; i < len; i ++){
            if(nums[i] > 0){
                dp[i] = max(nums[i], nums[i] * dp[i - 1]);
                negative[i] = min(nums[i], nums[i] * negative[i - 1]);
            }
            else if(nums[i] < 0){
                dp[i] = max(nums[i], nums[i] * negative[i - 1]);
                negative[i] = min(nums[i], nums[i] * dp[i - 1]);
            }
            else{
                dp[i] = 0;
                negative[i] = 0;
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i <len ;i ++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// 改进：优化空间，其实不需要dp数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int ans = INT_MIN, imax = 1, imin = 1;
        for(int i = 0; i < len; i ++){
            if(nums[i] < 0){
                swap(imax, imin); //如果nums[i] < 0，交换imax和imin
            }
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            ans = max(imax, ans);
        }
        return ans;
    }
};