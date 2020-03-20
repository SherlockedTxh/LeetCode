#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 动态规划
// 贴一个股票问题的通用解法，状态机的思想，很牛逼！

// 这个问题的「状态」有三个，第一个是天数，第二个是允许交易的最大次数，第三个是当前的持有状态（即之前说的 rest 的状态，我们不妨用 1 表示持有，0 表示没有持有）。

// 然后我们用一个三维数组就可以装下这几种状态的全部组合：
// dp[i][k][0 or 1]
// 0 <= i <= n-1, 1 <= k <= K
// n 为天数，大 K 为最多交易数
// 此问题共 n × K × 2 种状态，全部穷举就能搞定。
// 状态转移方程：

// dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
//               max(   选择 rest  ,           选择 sell      )

// 解释：今天我没有持有股票，有两种可能：
// 要么是我昨天就没有持有，然后今天选择 rest，所以我今天还是没有持有；
// 要么是我昨天持有股票，但是今天我 sell 了，所以我今天没有持有股票了。

// dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
//               max(   选择 rest  ,           选择 buy         )

// 解释：今天我持有着股票，有两种可能：
// 要么我昨天就持有着股票，然后今天选择 rest，所以我今天还持有着股票；
// 要么我昨天本没有持有，但今天我选择 buy，所以今天我就持有股票了。

// base case，即最简单的情况：

// dp[-1][k][0] = 0
// 解释：因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0 。
// dp[-1][k][1] = -infinity
// 解释：还没开始的时候，是不可能持有股票的，用负无穷表示这种不可能。
// dp[i][0][0] = 0
// 解释：因为 k 是从 1 开始的，所以 k = 0 意味着根本不允许交易，这时候利润当然是 0 。
// dp[i][0][1] = -infinity
// 解释：不允许交易的情况下，是不可能持有股票的，用负无穷表示这种不可能。

// 把上面的状态转移方程总结一下：

// base case：
// dp[-1][k][0] = dp[i][0][0] = 0
// dp[-1][k][1] = dp[i][0][1] = -infinity

// 状态转移方程：
// dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
// dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
        // 解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
        int len = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        int dp_pre_0 = 0; // 代表 dp[i-2][0]
        for(int i = 0; i < len; i++){
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
            dp_pre_0 = tmp;
        }
        return dp_i_0;
    }
};