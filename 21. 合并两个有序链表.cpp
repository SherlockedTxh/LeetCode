#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//没动脑子的辣鸡方法，可以不创造新节点合并两个链表，或者递归调用mergeTwoLists函数
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p && q){
            if(p->val < q->val){
                ans->next = p;
                ans = p;
                p = p->next;
            }
            else{
                ans->next = q;
                ans = q;
                q = q->next;
            }
        }
        while(p){
            ans->next = p;
            ans = p;
            p = p->next;
        }
        while(q){
            ans->next = q;
            ans = q;
            q = q->next;
        }
        return head->next;
    }
};
