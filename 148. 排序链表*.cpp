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

// 归并排序: 这题思路可能不难，但是代码比较长，注意小错误
// 由于题目要求空间复杂度是 O(1)，因此不能使用递归。因此这里使用 bottom-to-up 的算法来解决。
// bottom-to-up 的归并思路是这样的：先两个两个的 merge，完成一趟后，再 4 个4个的 merge，直到结束。举个简单的例子：[4,3,1,7,8,9,2,11,5,6].

// step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
// step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
// step=4: (1->2->3->4->7->8->9->11)->5->6
// step=8: (1->2->3->4->5->6->7->8->9->11)
// 链表里操作最难掌握的应该就是各种断链啊，然后再挂接啊。在这里，我们主要用到链表操作的两个技术：

// merge(l1, l2)，双路归并，我相信这个操作大家已经非常熟练的，就不做介绍了。
// cut(l, n)，可能有些同学没有听说过，它其实就是一种 split 操作，即断链操作。不过我感觉使用 cut 更准确一些，它表示，将链表 l 切掉前 n 个节点，并返回后半部分的链表头。

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0); 
        dummyHead.next = head;
        ListNode* p = head;
        int length = 0;
        while(p){ // 获取链表长度
            length++;
            p = p->next;
        }

        for(int size = 1; size < length; size *= 2){ // size表示每次切片的长度，注意是小于，等于时的上一步已经完成排序
            ListNode* curr = dummyHead.next;
            ListNode* tail = &dummyHead; // tail保存已处理的节点组成的新链表的尾节点，注意取地址，dummyHead不是指针
            
            while(curr){
                ListNode* left = curr; 
                ListNode* right = cut(curr, size); // left->@->@ right->@->@->@...
                curr = cut(right, size); // left->@->@ right->@->@  cur->@->...

                tail->next = merge(left, right);
                while(tail->next){
                    tail = tail->next; // 保持 tail 为尾部
                }
            }
        }
        return dummyHead.next;
    }

    ListNode* cut(ListNode* head, int size){
        ListNode* p = head;
        while(--size && p){ // 注意--size
            p = p->next;
        }
        if(p == NULL) return nullptr; // 剩余长度不够size

        ListNode* next = p->next;
        p->next = nullptr;
        return next; //返回切掉size的节点后的头节点
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);
        ListNode* p = &dummyHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                p = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2; // l1 l2不等长时把多余的部分接上
        return dummyHead.next;
    }
};