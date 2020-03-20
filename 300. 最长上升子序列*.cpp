#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 方法一：动态规划 O(n^2)
// dp[i] = max(dp[j]）+ 1, 其中 0 <= j < i, nums[j] < nums[i]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> dp = vector<int>(len, 1);
        int ans = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// 方法二：贪心 + 二分查找 这方法太巧妙了，我是傻子
// 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
// 基于上面的贪心思路，我们维护一个数组 d[i] ，表示长度为 i 的最长上升子序列的末尾元素的最小值，用 len 记录目前最长上升子序列的长度，起始时
// 最后整个算法流程为：
// 设当前已求出的最长上升子序列的长度为 len（初始时为1），从前往后遍历数组nums，在遍历到 nums[i] 时：
// 如果 nums[i]>d[len] ，则直接加入到 d 数组末尾，并更新 len=len+1；
// 否则，在 d 数组中二分查找，找到第一个比 nums[i] 小的数 d[k] ，并更新 d[k+1]=nums[i]。
// 官方题解：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        if(n == 0) return 0;
        vector<int> d = vector<int>(n + 1, 0);
        d[len] = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > d[len]){
                d[++len] = nums[i];
            }
            else{ // 二分查找
                int left = 1, right = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while(left <= right){
                    int mid = (left + right) >> 1;
                    if(d[mid] < nums[i]){
                        pos = mid; // pos是第一个比nums[i]小的下标
                        left = mid + 1;
                    }
                    else{
                        right = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};