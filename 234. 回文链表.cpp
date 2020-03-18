#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一：把链表的值复制到数组
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        int start = 0, end = nums.size() - 1;
        while(start < end){
            if(nums[start] != nums[end]){
                return false;
            }
            start ++;
            end --;
        }
        return true;
    }
};

// 方法二：反转后半个链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;

        // 找到前半部分的尾节点，反转后半部分
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

        // 检查是否是回文
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        while(p2){ // p2长度小于等于p1
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        // 把后半部分复原
        firstHalfEnd->next = reverseList(firstHalfEnd->next);
        return true;
    }

    ListNode* reverseList(ListNode* head){ //反转链表
        ListNode* newHead = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* tmp = curr;
            curr = curr->next;
            tmp->next = newHead;
            newHead = tmp;
        }
        return newHead;
    }

    ListNode* endOfFirstHalf(ListNode* head){ // 快慢指针，将链表分为两半，若长度是奇数，前半部分多1
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};