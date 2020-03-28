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


class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp = vector(K + 1, vector<int>(N + 1));
        //dp[i][j]表示 有i个鸡蛋、j次扔鸡蛋次数时可以测的最多楼层，扔鸡蛋次数最多不会超过N次（线性扫描）
        //case base:
        //dp[0][...] = 0;
        //dp[...][0] = 0;
        //默认初始化数组为0

        int ans = 0; // 要得到至少需要的最多扔鸡蛋机会，先初始化为0次
        while(dp[K][ans] < N){
            ans++;
            for(int i = 1; i <= K; i++){
                dp[i][ans] = dp[i][ans - 1] + dp[i - 1][ans - 1] + 1;
                //假设在某一层扔了一个鸡蛋，碎了：鸡蛋个数减1，机会减1；没碎：机会减1。
            }
        }
        return ans;
    }
};