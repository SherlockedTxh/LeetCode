#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 非严格后序
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        if(root == nullptr) return {};
        st.push(curr);
        while(!st.empty()){
            curr = st.top();
            ans.insert(ans.begin(), curr->val);
            st.pop();
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        return ans;
    }
};

// 严格后序
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while(!st.empty() || curr){
            while(curr){
                st.push(curr);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if(!st.empty() && st.top() == curr){
                curr = curr->right;
            }
            else{
                ans.push_back(curr->val);
                curr = nullptr;
            }
        }
        return ans;
    }
};