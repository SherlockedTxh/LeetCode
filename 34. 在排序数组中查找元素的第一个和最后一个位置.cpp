#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//写完发现这种方法有问题，对于所有元素一样的情况无法保证log(n)的复杂度。
//(left + right) / 2写成left + (right - left) / 2防止溢出
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left(0), right(nums.size() - 1), mid;
        vector<int> ans;
        while(left <= right){
            mid = (left + right) / 2;
            if(target < nums[mid]){
                if(target >= nums[left]){
                    right = mid - 1; 
                }
                else{
                    break;
                }
            }
            else if(target > nums[mid]){
                if(target <= nums[right]){
                    left = left + 1;
                }
                else{
                    break;
                }
            }
            else{
                ans.push_back(mid);
                ans.push_back(mid);
                int tmp = mid;
                while(1){
                    tmp --;
                    if(tmp >= left){
                        if(nums[tmp] == target){
                            ans.erase(ans.begin());
                            ans.insert(ans.begin(), tmp);
                        }
                    }
                    else{
                        break;
                    }
                }
                tmp = mid;
                while(1){
                    tmp ++;
                    if(tmp <= right){
                        if(nums[tmp] == target){
                            ans.pop_back();
                            ans.push_back(tmp);
                        }
                    }
                    else{
                        return ans;
                    }
                }
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

//优化后的方法，两次搜索，分别搜索左右边界，注意while条件、left和right的赋值和更新的变化、以及返回值的处理
//可以参考这篇文章，关于二分法讲的很详细：
//https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(left_bound(nums, target));
        ans.push_back(right_bound(nums, target));
        return ans;
    }
    int left_bound(vector<int>& nums, int target){
        if(nums.size() == 0) return -1;
        int left(0), right(nums.size()), mid;
        while(left < right){
            mid  = left + (right - left) / 2;
            if(target == nums[mid]){
                right = mid;
            }
            else if(target < nums[mid]){
                right = mid;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
        }
        if(left == nums.size()) return -1;
        return nums[left] == target ? left : -1;
    }
    int right_bound(vector<int>& nums, int target){
        if(nums.size() == 0) return -1;
        int left(0), right(nums.size()), mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(target == nums[mid]){
                left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
        }
        if(left == 0) return -1;
        return nums[left - 1] == target ? left - 1 : -1;
    }
};
