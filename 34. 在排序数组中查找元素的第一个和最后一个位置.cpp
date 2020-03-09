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
