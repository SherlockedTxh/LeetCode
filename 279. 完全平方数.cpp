#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// dfs 超时过不了
class Solution {
public:
    int numSquares(int n) {
        return dfs(n);
    }

    int dfs(int n){
        int ans = n;
        for(int i = int(sqrt(n)); i >= 2; i --){
            if(n - i * i == 0){
                return 1;
            }
            else if(n - i * i < 0){
                return INT_MIN;
            }
            else{
                ans = min(dfs(n - i * i) + 1, ans);
            }
        }
        return ans;
    }
};

// 动态规划
// 思路：
// 首先初始化长度为n+1的数组dp，每个位置都为0
// 如果n为0，则结果为0
// 对数组进行遍历，下标为i，每次都将当前数字先更新为最大的结果，即dp[i]=i，比如i=4，最坏结果为4=1+1+1+1即为4个数字
// 动态转移方程为：dp[i] = MIN(dp[i], dp[i - j * j] + 1)，i表示当前数字，j*j表示平方数
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1);
        for(int i = 1; i <= n; i ++){
            dp[i] = i;
            for(int j = 1; i - j * j >= 0; j ++){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

// 算法：
// 首先，我们准备一个小于给定数字 n 的完全平方数列表（称为 square_nums）。
// 在主循环中，将组合的大小（称为 count）从 1 迭代到 n，我们检查数字 n 是否可以除以组合的和，即 is_divided_by(n, count)。
// 函数 is_divided_by(n, count) 可以用递归的形式实现，汝上面所说。
// 在最下面的例子中，我们有 count==1，我们只需检查数字 n 是否本身是一个完全平方数。可以在 square_nums 中检查，即 n ∈ square_nums
// n∈square_nums。如果 square_nums 使用的是集合数据结构，我们可以获得比 n == int(sqrt(n)) ^ 2 更快的运行时间。
class Solution {
private:
    unordered_set<int> square_nums; // 包含可以当前所有比n小的平方数
public:
    int numSquares(int n) {
        for(int i = 1; i * i <= n; i++){
            square_nums.insert(i * i);
        }
        int count = 1;
        for(; count <= n; count++){
            if(is_devided_by(n, count)){
                return count;
            }
        }
        return n;
    }

    bool is_devided_by(int n, int count){
        if(count == 1){
            return square_nums.count(n);
        }

        for(int num : square_nums){
            if(is_devided_by(n - num, count - 1)){
                return true;
            }
        }
        return false;
    }
};
