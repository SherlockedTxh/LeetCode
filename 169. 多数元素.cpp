#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 这小小的简单题，其实有不少说法

// 方法一：排序，因为题中说明给定的数组总是存在多数元素，排序后n/2个元素就是答案
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return nums[len / 2];
    }
};

// 方法二：哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> hashmap;
        for(int i = 0; i < len; i ++){
            if(++ hashmap[nums[i]] > len / 2) return nums[i];
        }
        return -1;
    }
};

// 方法三 Boyer-Moore 投票算法
// Boyer-Moore 算法的本质和方法四中的分治十分类似。我们首先给出 Boyer-Moore 算法的详细步骤：
// 我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；
// 我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：
// 如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
// 如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
// 在遍历完成后，candidate 即为整个数组的众数。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int candidate = 0, count = 0;
        for(int i = 0; i < len; i ++){
            if(count == 0){
                candidate = nums[i];
            }
            count += candidate == nums[i] ? 1 : -1;
        }
        return candidate;
    }
};