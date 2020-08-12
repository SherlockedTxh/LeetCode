class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        return max(left, right);
    }
};
