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
// 由于对vector头部进行操作，效率会变差，用deque时间会更好,但是内存占用会变高
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

// deque
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        deque<TreeNode*> mydeque;
        vector<vector<int>> ans;
        mydeque.push_back(root);

        int level = 0;
        while(!mydeque.empty()){
            int size = mydeque.size();
            vector<int> layer;
            while(size--){
                TreeNode* tmp;
                if(level % 2 == 0){
                    tmp = mydeque.front();
                    mydeque.pop_front();
                    if(tmp->left) mydeque.push_back(tmp->left);
                    if(tmp->right) mydeque.push_back(tmp->right);
                }
                else{
                    tmp = mydeque.back();
                    mydeque.pop_back();
                    if(tmp->right) mydeque.push_front(tmp->right);
                    if(tmp->left) mydeque.push_front(tmp->left);
                }
                layer.push_back(tmp->val);
            }
            level++;
            ans.push_back(layer);
        }
        return ans;
    }
};
