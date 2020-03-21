#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 快速幂算法（递归）
// 如果已经得到x^(n/2)，那么根据n的奇偶性就可以得到x^n
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = - N;
        }
        return helper(x, N);
    }

    double helper(double x, long long n){
        if(n == 0){
            return 1.0;
        }
        double half = helper(x, n / 2);
        if(n % 2 == 0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }
};