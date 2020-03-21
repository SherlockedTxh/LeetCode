#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 双指针 left指向处理后的数组的最右边，right遍历整个数组，当两个指针指向的数字不相同，说明出现了一个前面没有的数字，复制到left+1的位置
// if(nums[left] != nums[right]) nums[left + 1] = nums[right]
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int ans = len, left = 0, right = 1;
        while(right < len){
            if(nums[left] != nums[right]){
                nums[++left] = nums[right];
            }
            else ans--;
            right++;
        }
        // nums.erase(nums.end() - (len - ans), nums.end());
        return ans;
    }
};