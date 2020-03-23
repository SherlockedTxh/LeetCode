#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历：始终选择中间位置左边元素(偶数情况)作为根节点
// 对于偶数个数的数组，要么选择中间位置左边的元素作为根节点，要么选择中间位置右边的元素作为根节点，不同的选择方案会创建不同的平衡二叉搜索树。
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right){
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(left <= mid -1) root->left = helper(nums, left, mid - 1);
        if(right >= mid + 1) root->right = helper(nums, mid + 1, right);
        return root;
    }
}; 