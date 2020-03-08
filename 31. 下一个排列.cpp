#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        for(int i = nums.size() - 1; i > 0; i --){
            if(nums[i] > nums[i - 1]){
                vector<int> rev;
                int pos = i;
                for(int j = nums.size() - 1; j > i; j --){
                    if(nums[j] > nums[i - 1]){
                        pos = j;
                        break;
                    }
                }
                int tmp = nums[i - 1];
                nums[i - 1] = nums[pos];
                nums[pos] = tmp;
                for(int k = i; k < nums.size(); k ++){
                    rev.push_back(nums[k]);
                }
                int len = rev.size();
                for(int k = 0; k < len; k ++){
                    nums[nums.size() - len + k] = rev[len - k - 1];
                }
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};