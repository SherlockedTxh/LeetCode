#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <set>
#include <ctype.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历 递归
class Solution {
private:
    vector<int> ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        ldr(root);
        return ans[k - 1];
    }
    void ldr(TreeNode* root){
        if(root->left){
            ldr(root->left);
        }
        ans.push_back(root->val);
        if(root->right){
            ldr(root->right);
        }
    }
};

// 中序遍历 迭代 用了栈 可以不用遍历整棵树
class Solution {
private:
    vector<int> ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(1){
            // 找到最小的节点
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            // 找到第k小的元素，程序就可以结束了
            if(--k == 0){
                return root->val;
            }
            root = root->right;
        }
    }
};