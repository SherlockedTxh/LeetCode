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

// 可以用哈希表存储地址，判断两个是否有指向相同地址的指针，但是这样不是O(1)的内存
// 这里用一个浪漫的算法，双指针法：
// 用两个指针pA和pB，分别初始化为A，B的头节点，向后逐个遍历，
// pA到达尾部时，重定位为B的头节点，pB到达尾部时，重定位为A的头节点，
// 若有交点则会相遇在交点，因为a + all +b = b + all + a，若没有交点，则会同时指向NULL
// 引用一条leetcode的评论：
// “这个算法也浪漫了吧，错的人迟早会走散，而对的人迟早会相逢！”

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if(headA == NULL || headB == NULL){
            return nullptr;
        }
        while(a != b){
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};