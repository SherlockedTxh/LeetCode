#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <tuple>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//     |
//     a
//    / \
//   b   c
// 三种情况：
// 1. b + a + c。
// 2. b + a + a 的父结点。
// 3. a + c + a 的父结点。
class Solution {
public:
    int ans = INT_MIN;
    int helper(TreeNode* root){
        if(root == nullptr) return 0; // 学习了NULL和nullptr的区别，c++中NULL为整数0，这里用NULL也可以
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        int lr = root->val + left + right; //root为根节点，或者第一种情况
        ans = max(ans, lr);
        return root->val + max(left, right); // 第2 3种情况
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};