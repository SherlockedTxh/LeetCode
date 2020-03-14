#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
using namespace std;

// 用哈希表存储，优化搜索时间
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int i : nums){
            hashset.insert(i);
        }
        int ans = 0, currnum, currlength;
        for(int num : nums){
            if(hashset.count(num - 1)) continue; //如果哈希表中存在num-1，说明这个值已经被搜索过，跳过
            currnum = num;
            currlength = 0;
            while(hashset.count(currnum)){
                currnum ++;
                currlength ++;
            }
            ans = max(ans, currlength);
        }
        return ans;
    }
};