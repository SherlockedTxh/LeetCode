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

// 方法一：递归，记录当前节点取值上下界
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, -INFINITY, INFINITY);
    }

    bool check(TreeNode* root, double low, double high){
        if(root == NULL) return true;

        if(root->val <= low) return false;
        if(root->val >= high) return false;

        if(!check(root->left, low, root->val)){
            return false;
        }
        if(!check(root->right, root->val, high)){
            return false;
        }
        return true;
    }
};

// 方法二：中序遍历，遍历的数字应该是从小到大
// Notes: 这题有一个测试用例是[-2147483648]，正好是INT_MIN
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> ldr;
        TreeNode* curr = root;
        double tmp = -INFINITY; //注意是double，int过不了
        while(!ldr.empty() || curr){
            while(curr){
                ldr.push(curr);
                curr = curr->left;
            }
            if(tmp >= ldr.top()->val) return false;
            tmp = ldr.top()->val;
            curr = ldr.top();
            ldr.pop();
            curr = curr->right;
        }
        return true;
    }
};
