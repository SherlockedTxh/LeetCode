#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

//p0为0的右边界，p2为2的左边界，curr为当前的节点，当curr遇到p2结束循环
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int p0 = -1, p2 = len, curr = 0;
        while(curr < p2 && curr < len){
            if(nums[curr] == 0){
                swap(nums[curr], nums[p0 + 1]);
                p0 ++;
            }
            if(nums[curr] == 2){
                swap(nums[curr], nums[p2 - 1]);
                p2 --;
            }
            else{
                curr ++;
            }
        }
    }
};