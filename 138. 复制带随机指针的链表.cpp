#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 方法一：递归
// 算法
// 从 头 指针开始遍历整个图。
// 当我们遍历到某个点时，如果我们已经有了当前节点的一个拷贝，我们不需要重复进行拷贝。
// 如果我们还没拷贝过当前节点，我们创造一个新的节点，并把该节点放到已访问字典中，即：
// visited_dictionary[current_node] = cloned_node_for_current_node.
// 我们针对两种情况进行回溯调用：一个顺着 random 指针调用，另一个沿着 next 指针调用。然后我们分别对两个指针进行函数递归调用：

class Solution {
public:
    unordered_map<Node*, Node*> visitedHash;
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr) return nullptr;

        if(visitedHash.count(head)){
            return visitedHash[head];
        }

        Node* node = new Node(head->val);
        visitedHash[head] = node; // 标记以访问的节点

        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }
};

// 方法二 拷贝每个节点，将拷贝的节点都连在原来对应节点的后面。O(1)的额外空间
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr) return nullptr;

        // 拷贝每个节点，将拷贝的节点都连在原来对应节点的后面
        Node* ptr = head;
        while(ptr){
            Node* node = new Node(ptr->val);
            node->next = ptr->next;
            ptr->next = node;
            ptr = node->next;
        }

        // 拷贝random
        ptr = head;
        while(ptr->next){
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }

        // 拷贝next并还原原链表
        ptr = head;
        Node* newHead = head->next;
        Node* clone = newHead;
        while(ptr){
            ptr->next = clone->next;
            clone->next = clone->next ? clone->next->next : nullptr;
            ptr = ptr->next;
            clone = clone->next;
        }

        return newHead;
    }
};
