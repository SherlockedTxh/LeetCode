#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a =0 ,b =0 ;
        int carry = 0; //进位
        ListNode *head = new ListNode(0);
        ListNode *p = head;

        while(l1 || l2 || carry){ //l1,l2均遍历完成并且无进位
            if(l1) 
                a = l1->val;
            else 
                a = 0;
            if(l2) 
                b = l2->val;
            else 
                b = 0;
            int sum = a + b + carry;
            ListNode *q = new ListNode(sum % 10);
            p->next = q;
            p = p->next;
            carry = sum / 10;
            if(l1) 
                l1 = l1->next;
            if(l2) 
                l2 = l2->next;
        }
        return head->next; 
    }
};