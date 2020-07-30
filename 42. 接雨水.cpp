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

// 双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0, ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                height[left] >= max_left ? (max_left = height[left]) : ans += (max_left - height[left]);
                left++;
            }
            else{
                height[right] >= max_right ? (max_right = height[right]) : ans += (max_right - height[right]);
                right--;
            }
        }
        return ans;
    }
};
