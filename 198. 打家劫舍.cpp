#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 动态规划 dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp = vector<int>(len);
        if(len == 0) return 0;
        for(int i = 0; i < len; i ++){
            if(i == 0){
                dp[i] = nums[i];
            }
            else if(i == 1){
                dp[i] = max(nums[i], dp[i - 1]);
            }
            else{
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
        }
        return dp[len - 1];
    }
};

// 优化 不需要数组也可 在数组前面加两个0，可以极大简化代码
class Solution {
public:
    int rob(vector<int>& nums) {
        int preMax = 0;
        int curMax = 0;
        int tmp;
        for(int num : nums){
            int tmp = preMax;
            preMax = curMax;
            curMax = max(curMax, tmp + num);
        }
        return curMax;
    }
};