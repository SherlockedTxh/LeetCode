#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
    struct cmp{
        bool operator() (ListNode* a, ListNode* b){ // *知识点：仿函数
            return a->val > b->val; //优先队列默认是大顶堆重载<，本题需要小顶堆与之相反
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode* >, cmp> heapk;
        for(auto p : lists){
            if(p){
                heapk.push(p); //把每个链表的表头加入队列
            }
        }
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        while(!heapk.empty()){
            ListNode* top = heapk.top();
            p->next = top;
            p = top;
            heapk.pop();
            if(top->next){
                heapk.push(top->next);
            }
        }
        return dummyHead->next;
    }
};
