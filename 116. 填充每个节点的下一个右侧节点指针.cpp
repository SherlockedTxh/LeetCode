#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 没看清楚题目 用了队列 违反题意了
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return {};
        queue<Node*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size() - 1;
            Node* pre = que.front();
            que.pop();
            if(pre ->left) que.push(pre->left);
            if(pre->right) que.push(pre->right);
            while(size--){
                Node* cur = que.front();
                que.pop();
                pre->next = cur;
                pre = cur;
                if(pre ->left) que.push(pre->left);
                if(pre->right) que.push(pre->right);
            }
        }
        return root;
    }
};

// 算法 满巧妙的
// 从根节点开始，由于第 0 层只有这一个节点，所以不需要连接。
// 直接为第 1 层节点建立 next 指针即可。
// 该算法中需要注意的一点是，当我们为第 N 层节点建立 next 指针时，处于第 N−1 层。当第 N 层节点的 next 指针全部建立完成后，移至第 N 层，建立第 N+1 层节点的 next 指针。
// 遍历某一层的节点时，这层节点的 next 指针已经建立。因此我们只需要知道这一层的最左节点，就可以按照链表方式遍历，不需要使用队列。

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        
        Node* leftmost = root;
        while(leftmost->left){
            Node* head = leftmost;
            while(head){
                head->left->next = head->right; // 父节点相同，左子节点连接右子节点
                if(head->next){
                    head->right->next = head->next->left; // 如果父节点有next，右子节点连接后一个的左子节点
                }
                head = head->next; // 当前层已经用next相连，可以用next遍历每一层
            }
            leftmost = leftmost->left; // leftmost修改为下一层的最左边节点
        }
        return root;
    }
};