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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hashset;       
        while(head){
            if(hashset.count(head)){
                return true;
            }
            hashset.insert(head);
            head = head->next;
        }
        return false;
    }
};

// 方法二：快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next ==NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};