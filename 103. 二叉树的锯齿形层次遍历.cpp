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

// BFS 层次遍历 对于奇数行用每次往vector的头insert元素
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> myqueue;
        vector<vector<int>> ans;
        myqueue.push(root);

        int level = 0;
        vector<int> layer;
        while(!myqueue.empty()){
            int size = myqueue.size();
            while(size--){
                TreeNode * tmp = myqueue.front();
                myqueue.pop();
                if(level % 2 == 0){
                    layer.push_back(tmp->val);
                }
                else{
                    layer.insert(layer.begin(), tmp->val);
                }
                if(tmp->left) myqueue.push(tmp->left);
                if(tmp->right) myqueue.push(tmp->right);
            }
            level++;
            ans.push_back(layer);
            layer.clear();
        }
        return ans;
    }
};