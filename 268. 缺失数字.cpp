#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 方法一：先往数组最后添加一个元素n，然后遍历数组nums[abs(nums[i])] *= -1，
// 最后数组中唯一的正数的下标就是缺失的数字，如果没有正数，那么就是0对应的下标
// 我想到了这个方法却没想到位运算跟数学方法。。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int pos = -1, len = nums.size();
        nums.push_back(len + 1);
        for(int i = 0; i < len; i++){
            nums[abs(nums[i])] *= -1;
        }
        bool flag = false;
        for(int i = 0; i <= len; i++){
            if(nums[i] > 0){
                pos = i;
                break;
            }
            else if(nums[i] == 0){
                if(pos == -1) pos = i;
            } 
        }
        return pos;
    }
};

// 位运算
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size(), n = len;
        for(int i = 0; i < len; i++){
            n ^= (i ^ nums[i]);
        }
        return n;
    }
};

// 数学方法 求和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int expectedSum = (1 + len) * len / 2 ,actualSum = 0;
        for(int i = 0; i < len; i++){
            actualSum += nums[i];
        }
        return expectedSum - actualSum;
    }
};