#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 方法一：双向队列deque
// 第一直觉是最大堆，但是窗口划出队头priority_queue不好操作，所以用了deque
// *Note：vector，list，deque的区别
// 声明变量 deque<int>window，用于存储下标。这个变量有以下 特点:
//     变量的最前端（也就是 window.front()）是此次遍历的最大值的下标
//     当我们遇到新的数时，将新的数和双项队列的末尾（也就是window.back()）比较，如果末尾比新数小，则把末尾扔掉，直到该队列的末尾比新数大或者队列为空的时候才停止，做法有点像使用栈进行括号匹配。
//     双项队列中的所有值都要在窗口范围内
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if(k == 0 || len == 0) return {};
        vector<int> ans;
        deque<int> window;

        // 处理前k个
        for(int i = 0; i < k; i ++){
            while(!window.empty() && nums[i] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i);
        }
        ans.push_back(nums[window.front()]);

        for(int i = k; i < len; i ++){
            if(!window.empty() && window.front() == i - k){
                window.pop_front();
            }
            while(!window.empty() && nums[i] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i);
            ans.push_back(nums[window.front()]);
        }

        return ans;
    }
};

// 方法二：动态规划 分块法 (这个方法真的很难想到，反正我是想不到)下面是leetcode官方提供的思路
// 算法的思想是将输入数组分割成有 k 个元素的块。
// 若 n % k != 0，则最后一块的元素个数可能更少。
// 开头元素为 i ，结尾元素为 j 的当前滑动窗口可能在一个块内，也可能在两个块中。
// 建立数组 left， 其中 left[j] 是从块的开始到下标 j 最大的元素，方向 左->右。
// 为了处理窗口横跨两个块的情况，我们需要数组 right，其中 right[j] 是从块的结尾到下标 j 最大的元素，方向 右->左。right 数组和 left 除了方向不同以外基本一致。
// 两数组一起可以提供两个块内元素的全部信息。考虑从下标 i 到下标 j的滑动窗口。 根据定义，right[i] 是左侧块内的最大元素， left[j] 是右侧块内的最大元素。因此滑动窗口中的最大元素为 max(right[i], left[j])。
// 算法
//     从左到右遍历数组，建立数组 left。
//     从右到左遍历数组，建立数组 right。
//     建立输出数组 max(right[i], left[i + k - 1])，其中 i 取值范围为 (0, n - k + 1)。
// https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if(k == 0 || len == 0) return {};

        vector<int> left = vector<int>(len);
        left[0] = nums[0];
        vector<int> right = vector<int>(len);
        right[len - 1] = nums[len - 1];

        for(int i = 1; i < len; i ++){
            // 左到右
            if(i % k == 0) left[i] = nums[i]; //块的第一个元素
            else left[i] = max(left[i - 1], nums[i]);

            // 右到左
            int j = len - i - 1;
            if((j + 1) % k == 0) right[j] = nums[j];
            else right[j] = max(right[j + 1], nums[j]);
        }

        vector<int> ans;
        for(int i = 0; i < len - k + 1; i ++){
            ans.push_back(max(left[i + k - 1], right[i]));
        }

        return ans;
    }
};