#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//首先想到的是DFS每次传入删掉添加过的元素后的vector，但是nums是引用，删除会改变nums，所以使用swap
class Solution {
private:
    vector<vector<int>> ans;
public:
    void DFS(int start, vector<int>& nums){
        if(start == nums.size()){
            ans.push_back(nums);
        }
        else{
            for(int i = start; i < nums.size(); i ++){
                swap(nums[start], nums[i]);
                DFS(start + 1, nums);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        DFS(0, nums);
        return ans;
    }
};