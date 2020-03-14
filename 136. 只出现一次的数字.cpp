#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
using namespace std;

// 位运算 两个相同的数异或结果为0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, len = nums.size();
        for(int i = 0; i < len; i ++){
            a = a ^ nums[i];
        }
        return a;
    }
};