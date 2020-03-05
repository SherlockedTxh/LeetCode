#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        if(len < 3) 
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i ++){
            if(nums[i] > 0){ //nums[i]>0,排序后后面都是正数相加不可能为0
                return ans;
            }
            if(i > 0 && nums[i] == nums[i - 1]){ //去除重复解
                continue;
            }
            int left = i + 1, right = len - 1; //左指针=i-1，右指针=n-1
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    ans.push_back({nums[i], nums[left],  nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){ //去除重复解
                        left ++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right --;
                    }
                    left ++;
                    right --;
                }
                else if(nums[i] + nums[left] + nums[right] > 0){ //和大于0，右指针左移
                    right --;
                }
                else { //和小于0，左指针右移
                    left ++;
                }
            }
        }
        return ans;
    }
};