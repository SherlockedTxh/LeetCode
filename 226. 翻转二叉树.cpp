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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        queue<TreeNode* > myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){
            TreeNode* tmp = myqueue.front();
            myqueue.pop();
            swap(tmp->left, tmp->right);
            if(tmp->left) myqueue.push(tmp->left);
            if(tmp->right) myqueue.push(tmp->right);
        }
        return root;
    }
};