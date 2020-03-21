#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 这题的方法秀的我头皮发麻，我是想破脑袋也没想出来。。
// 算法 索引作为哈希表 在原数组上建立
// 检查 1 是否存在于数组中。如果没有，则已经完成，1 即为答案。
// 如果 nums = [1]，答案即为 2 。
// 将负数，零，和大于 n 的数替换为 1 。因为首次缺失的正数一定小于或等于 n + 1 。
// 遍历数组。当读到数字 a 时，替换第 a 个元素的符号。
// 注意重复元素：只能改变一次符号。由于没有下标 n ，使用下标 0 的元素保存是否存在数字 n。
// 再次遍历数组。返回第一个正数元素的下标。
// 如果 nums[0] > 0，则返回 n 。
// 如果之前的步骤中没有发现 nums 中有正数元素，则返回n + 1。
// https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        
        bool flag = false; // 判断数组中是否有1
        for(int i = 0; i < len; i++){
            if(nums[i] == 1){
                flag = true;
            }
            else if(nums[i] <= 0 || nums[i] > len){ // 将负数，零，和大于 n 的数替换为 1
                nums[i] = 1;
            }
        }
        if(!flag) return 1;

        // 处理数组使之都为正数
        for(int a : nums){
            if(abs(a) == len){
                if(nums[0] > 0) nums[0] *= -1; // 由于没有下标 n ，使用下标 0 的元素保存是否存在数字 n
            }
            else if(nums[abs(a)] > 0) nums[abs(a)] *= -1; // 遍历数组。当读到数字 a 时，替换第 a 个元素的符号
        }

        // 找第一个正数
        for(int i = 1; i < len; i++){
            if(nums[i] > 0) return i;
        }
        if(nums[0] > 0) return len;
        return len + 1;
    }
};