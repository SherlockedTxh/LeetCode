#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 二分查找
// 抽屉原理：桌上有十个苹果，要把这十个苹果放到九个抽屉里，无论怎样放，我们会发现至少会有一个抽屉里面放不少于两个苹果。
// 思路：这道题要求我们查找的数是一个整数，并且给出了这个整数的范围（在 1 和 n 之间，包括 1 和 n），并且给出了一些限制。
// 通过一个具体的例子来分析应该如何编写代码：
// 以 [1, 2, 2, 3, 4, 5, 6, 7] 为例，一共 8 个数，n + 1 = 8，n = 7，根据题目意思，每个数都在 1 和 7 之间。
// 例如：区间 [1, 7] 的中位数是 4，遍历整个数组，统计小于等于 4 的整数的个数，至多应该为 4 个。
// 换句话说，整个数组里小于等于 4 的整数的个数如果严格大于 4 个，就说明重复的数存在于区间 [1, 4]，它的反面是：重复的数存在于区间 [5, 7]。
// 于是，二分法的思路是先猜一个数（有效范围 [left, right]里的中间数 mid），然后统计原始数组中小于等于这个中间数的元素的个数 cnt，
// 如果 cnt 严格大于 mid，依然根据抽屉原理，重复元素就应该在区间 [left, mid] 里。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 给定一个包含 n + 1 个整数的数组 nums，所以nums中最大值小于等于nums.size() - 1
        int n = nums.size() - 1; 

        int low = 1, high = n; // 数组中数字取值的上下界
        int mid = (low + high) / 2; // mid 中位数
        while(low <= high){
            mid = (low + high) / 2;
            int cnt = 0;
            for(int i = 0; i <= n; i++){
                if(nums[i] <= mid){
                    cnt ++;
                    if(cnt > mid) break;
                }
            }
            if(cnt > mid){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

// 快慢指针 leetcode官方给出的方法中唯一满足条件的，但是我没懂原理。。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int ptr1 = nums[0];
        int ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};