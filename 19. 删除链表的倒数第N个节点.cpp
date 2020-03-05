#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head; //设置哑节点方便删除head的情况
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        
        for(int i = 0; i < n; i ++){
            p = p->next;
        }
        while(p->next){
            p = p->next;
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        
        return ans;
    }
};
