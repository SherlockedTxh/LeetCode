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

// 递归 注意传递层数
class Solution {
private:
    vector<vector<int>> ans;
public:
    void lo(TreeNode* t, int level){
        if(level == ans.size()){ //当前层数第一次出现，新建一个该层数对应的数组
            ans.push_back(vector<int>());
        }
        ans[level].push_back(t->val);
        if(t->left) lo(t->left, level + 1);
        if(t->right) lo(t->right, level +1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return ans;
        lo(root, 0);
        return ans;
    }
};