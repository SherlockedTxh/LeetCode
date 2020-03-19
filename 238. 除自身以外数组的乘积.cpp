#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 动态规划 算法：
// 初始化两个空数组 L 和 R。对于给定索引 i，L[i] 代表的是 i 左侧所有数字的乘积，R[i] 代表的是 i 右侧所有数字的乘积。
// 我们需要用两个循环来填充 L 和 R 数组的值。对于数组 L，L[0] 应该是 1，因为第一个元素的左边没有元素。对于其他元素：L[i]=L[i-1]*nums[i-1]。
// 同理，对于数组 R，R[length-1] 应为 1。length 指的是输入数组的大小。其他元素：R[i]=R[i+1]*nums[i+1]。
// 当 R 和 L 数组填充完成，我们只需要在输入数组上迭代，且索引 i 处的值为：L[i]*R[i]。
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> L = vector<int>(len);
        vector<int> R = vector<int>(len);

        // 初始化L，R
        L[0] = 1, R[len - 1] = 1;
        for(int i = 1; i < len; i ++){
            L[i] = L[i - 1] * nums[i - 1];
        }
        for(int i = len - 2; i >= 0; i --){
            R[i] = R[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < len; i ++){
            L[i] *= R[i];
        }
        return L;
    }
};

// 优化为空间复杂度 O(1) 的方法
// 算法：
// 初始化 answer 数组，对于给定索引 i，answer[i] 代表的是 i 左侧所有数字的乘积。
// 构造方式与之前相同，只是我们视图节省空间。
// 这种方法的唯一变化就是我们没有构造 R 数组。而是用一个遍历来跟踪右边元素的乘积。并更新数组 
// answer[i]=answer[i]*R。然后 R=R*nums[i]
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans = vector<int>(len);
        ans[0] = 1;
        for(int i = 1; i < len; i ++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int R = 1;
        for(int i = len - 1; i >= 0; i --){
            ans[i] *= R;
            R *= nums[i];
        }
        return ans;
    }
};