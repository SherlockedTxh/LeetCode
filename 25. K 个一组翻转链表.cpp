#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = k;
        ListNode *tail = head;
        if(head == nullptr) return head;
        while(cnt){
            if(tail == nullptr) break;
            tail = tail->next;
            cnt--;
        }
        if(cnt != 0) return head;
        ListNode *dummyHead = new ListNode(0);
        ListNode *newtail = head;
        while(head != tail){
            ListNode *tmp = head->next;
            head->next = dummyHead->next;
            dummyHead->next = head;
            head = tmp;
        }
        newtail->next = reverseKGroup(tail, k);
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};