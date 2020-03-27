#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <set>
#include <ctype.h>
using namespace std;

// 动态规划 自下而上
// dp[i] = min(dp[i], dp[i - coin] + 1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp = vector<int>(amount + 1, amount);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// 贪心 + dfs
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) return;

        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
        {
            coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
        }
    }
};