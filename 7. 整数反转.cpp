#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// int范围 2^31-1=2147483647,-2^31=-2147483648
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            // 提前判断ans乘10之后是否会溢出
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && x % 10 > 7)) return 0;
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && x % 10 < -8)) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};