#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 这题要求设计最小栈，我用了两个栈来实现，不知道算不算违法，我觉得目的应该是考察O(1)时间搜索
// 不能用栈的话可以用list，因为list的搜索也是O(1)
class MinStack {
private:
    stack<int> mystack;
    stack<int> minstack; //用于检索最小元素
public:
    /** initialize your data structure here. */
    MinStack() {
        this->mystack = stack<int>();
        this->minstack = stack<int>();
    }
    
    void push(int x) {
        mystack.push(x);
        if(minstack.empty() || x <= minstack.top()){
            minstack.push(x);
        }
    }
    
    void pop() {
        if(mystack.top() == minstack.top()){
            minstack.pop();
        }
        mystack.pop();
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */