#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 感觉是道数学题。。下面是动态规划推导过程：
// G(n):长度为n的序列的不同二叉搜索树个数。
// F(i,n):以i为根的不同二叉搜索树个数,1<=i<=n
// 给定序列 1 ... n，我们选出数字 i 作为根，则对于根 i 的不同二叉搜索树数量F(i,n)是左右子树个数的笛卡尔积
// G(n) = (G(i-1)*G(n-i)) i从1到n求和
// https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1);
        G[0] = G[1] = 1;
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= i; j ++){
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};