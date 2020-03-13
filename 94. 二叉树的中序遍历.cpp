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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> ldr;
        vector<int> ans;
        TreeNode* curr = root;
        while(!ldr.empty() || curr){
            while(curr){
                ldr.push(curr);
                curr = curr->left;
            }
            ans.push_back(ldr.top()->val);
            curr = ldr.top();
            ldr.pop();
            curr = curr->right;
        }
        return ans;
    }
};