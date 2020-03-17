#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 逐个删除原链表节点，一次作为新链表的头节点插入
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* tmp = head;
        while(head){
            head = head->next;
            tmp->next = newHead;
            newHead = tmp;
            tmp = head;
        }
        return newHead;
    }
};
