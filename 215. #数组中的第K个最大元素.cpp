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

// 基于快排的思想
class Solution {
public:
    int quickSelect(vector<int>& nums, int l, int r, int index){
        int q = randomPartition(nums, l, r);
        if (q == index) {
            return nums[q];
        } 
        else {
            return q < index ? quickSelect(nums, q + 1, r, index) : quickSelect(nums, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& nums, int l, int r){ // 随机pivot
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    inline int partition(vector<int>& nums, int l, int r){ // 快排
        int x = nums[r], i = l - 1;
        for(int j = l; j < r; j++){
            if(nums[j] <= x){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
