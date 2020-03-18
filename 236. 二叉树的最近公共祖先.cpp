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

// 方法一：递归
// 分别在左右子树中递归寻找这两个节点，找到任意一个，返回这个节点的指针
// 如果在一边没有找到两个节点，那么这两个节点一定在另一边，
// 如果两个节点分别在两边，那么root是他们的最近公共祖先。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) 
            return nullptr;
        if(root == p || root == q) 
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};