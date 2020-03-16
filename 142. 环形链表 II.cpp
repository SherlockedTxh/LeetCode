#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一：哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;       
        while(head){
            if(hashset.count(head)){
                return head;
            }
            hashset.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

// 方法二：快慢指针
// 1.快指针1次走2步，慢指针1次走1步。所以快指针总是走了慢指针两倍的路。
// 2.回顾一下阶段1的过程，设头节点到入环点的路途为 n, 那么慢指针走了入环路途的一半（n/2）时，快指针就到达入环点了(走完n了)。
// 3.慢指针再继续走完剩下的一般入环路途（剩下的n/2），到达入环点时，快指针已经在环内又走了一个 n 那么远的路了。
// 4.为了方便理解，这里先讨论环很大，大于n的情况（其他情况后文补充）。此时，慢指针正处于入环点，快指针距离入环点的距离为n。环内路，可以用此时快指针的位置分割为两段，前面的 n 部分，和后面的 b 部分。
// 5.此时开始继续快慢指针跑圈，因为已经在环内了，他们其实就是在一条nbnbnbnbnbnbnb（无尽nb路）上跑步。
// 6.慢指针从入环处开始跑b步，距离入环处就剩下了n。此时，快指针则是从距离入环处n步远的位置开始跑了2b步，距离入环处也是剩下了n。他们相遇了，并且距离入环处的距离就是n，n就是头节点到入环点的距离
class Solution {
public:
    ListNode *hasCycle(ListNode *head) {
        // 注意slow和fast都是从head开始跑，上一题无所谓
        if(head == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *meet = hasCycle(head);
        if(meet == nullptr) return NULL;
        ListNode *p = head;
        while(p != meet){
            p = p->next;
            meet = meet->next;
        }
        return meet;
    }
};