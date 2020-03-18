#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 排序。。
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// 堆 
// 升序队列
// priority_queue <int,vector<int>,greater<int> > q;
// 降序队列
// priority_queue <int,vector<int>,less<int> >q;
// greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heapk; // 小顶堆
        for(int num : nums){
            if(heapk.size() < k){
                heapk.push(num);
            }
            else{
                if(num > heapk.top()){
                    heapk.pop();
                    heapk.push(num);
                }
            }
        }
        return heapk.top();
    }
};