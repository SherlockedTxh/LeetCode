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
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        return a->val == b->val && check(a->left, b->right) && check(a->right, b->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

// 方法二：迭代 使用队列
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* a = q.front();
            q.pop();
            TreeNode* b = q.front();
            q.pop();
            if(a == NULL && b == NULL) continue;
            if(a == NULL || b == NULL) return false;
            if(a->val != b->val) return false;
            q.push(a->left);
            q.push(b->right);
            q.push(a->right);
            q.push(b->left);
        }
        return true;
    }
};