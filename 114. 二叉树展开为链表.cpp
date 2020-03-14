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

// 方法一：前序遍历把节点存入链表
class Solution {
private:
    queue<TreeNode*> q;
public:
    void preorder(TreeNode* t){
        q.push(t);
        if(t->left) preorder(t->left);
        if(t->right) preorder(t->right);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        preorder(root);
        TreeNode* pre = root;
        TreeNode* curr;
        q.pop();
        pre->left = NULL;
        while(!q.empty()){
            curr = q.front();
            curr->left = NULL;
            pre->right = curr;
            q.pop();
            pre = curr;
        }
    }
};

// 方法二：把左子树放到右边，然后把原右子树连到原左子树的最右下的节点的右边
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode * tmp;
        while(root != NULL){
            if(root->left == NULL){
                root = root->right;
            }
            else{
                tmp = root->left;
                while(tmp->right != NULL){
                    tmp = tmp->right;
                }
                tmp->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

// 方法三 后序遍历 每次遍历一个节点把它作为尾节点
// 虽然结果的顺序是前序遍历的顺序，但是如果用前续遍历，会丢失根节点的右子树
