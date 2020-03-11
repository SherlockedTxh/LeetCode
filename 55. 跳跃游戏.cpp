#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

//最远能到达某个位置，就一定能到达它前面的任何位置。
//常规解法应该是动态规划，1)自顶向下 2)自底向上
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furtherest_Jump = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(i > furtherest_Jump){
                return false;
            }
            furtherest_Jump = max(furtherest_Jump, i + nums[i]);
        }
        return true;
    }
};