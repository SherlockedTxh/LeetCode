#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 用了股票通用解法，可以看309. 最佳买卖股票时机含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = -INFINITY, len = prices.size();
        for(int i = 0; i < len; i++){
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_i_0 - prices[i]);
        }
        return dp_i_0;
    }
};

// 本题可以用一个简单的贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0, len = prices.size();
        for(int i = 1; i < len; i++){
            if(prices[i] > prices[i - 1]) maxprofit += (prices[i] - prices[i - 1]);
        }
        return maxprofit;
    }
};