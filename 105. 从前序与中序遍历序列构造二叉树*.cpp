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

// 递归 preorder 中的第一个元素一定是树的根，这个根又将 inorder 序列分成了左右两棵子树。
// 只需要将先序遍历的数组中删除根元素，然后重复上面的过程处理左右两棵子树。

class Solution {
private:
    unordered_map<int, int> index; //中序遍历每个值对应的下表，方便搜索，因为题中说明了树中没有重复元素
    int root_index = 0; //preorder中当前关注节点的下标
    vector<int> preorder;
    vector<int> inorder;
public:
    TreeNode* helper(int left, int right){ // 注意判断条件是left == right，所以是坐包括又不包括
        if(left == right) return NULL;
        int root_val = preorder[root_index];
        TreeNode* root = new TreeNode(root_val);
        root_index ++;
        root->left = helper(left, index[root_val]);
        root->right = helper(index[root_val] + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        for(int i = 0; i < inorder.size(); i ++){
            index[inorder[i]] = i;
        }
        return helper(0, inorder.size());
    }
};