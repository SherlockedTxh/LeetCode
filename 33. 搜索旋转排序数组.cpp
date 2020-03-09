#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

// 很容易想到二分法：
// 1. nums[0] <= nums[mid]（0 - mid不包含旋转）且nums[0] <= target <= nums[mid] 时 high 向前规约；
// 2. nums[mid] < nums[0]（0 - mid包含旋转），target <= nums[mid] < nums[0] 时向前规约（target 在旋转位置到 mid 之间）
// 3. nums[mid] < nums[0]，nums[mid] < nums[0] <= target 时向前规约（target 在 0 到旋转位置之间）
// 4. 其他情况向后规约
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), mid;
        int left = 0, right = len - 1;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] < nums[mid] && target <= nums[mid] && target >= nums[left]){
                right = mid - 1;
            }
            else if(nums[left] > nums[mid] && target >= nums[left]){
                right = mid - 1;
            }
            else if(nums[left] > nums[mid] && target <= nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
};
