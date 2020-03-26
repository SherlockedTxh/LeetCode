#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <set>
#include <ctype.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node->next;
        ListNode* pre = node;
        while(cur->next){
            pre->val = cur->val;
            cur = cur->next;
            pre = pre->next;
        }
        pre->val = cur->val;
        pre->next = nullptr;
        return;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};