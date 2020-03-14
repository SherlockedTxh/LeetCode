#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
#include <tuple>
using namespace std;

// 一开始在for循环里用了i < prices.size()，击败20%多，改成在外面赋值，就击败97.5%。。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX, ans = 0, len = prices.size();
        for(int i = 0; i < len; i ++){
            low = min(low, prices[i]);
            ans = max(ans, prices[i] - low);
        }
        return ans;
    }
};