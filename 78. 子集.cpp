#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 思路：先往ans中加入一个空数组，对于每个nums中的数字进行如下操作：
// 对于ans中的每个数组，往ans中加入该数字与这个数组组成的新数组，(不修改原数组)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(vector<int>());
        int len = 0;
        for(int a : nums){
            len = ans.size();
            for(int i = 0; i < len; i++){
                tmp = ans[i];
                tmp.push_back(a);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};