#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

// 笨方法
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        for(int i = 1; i < x; i ++){
            if(x / i < i) return i - 1;
        }
        return 1;
    }
};

// 二分法 x的平方根 < x / 2 + 1
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x / 2 + 1, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(x / mid < mid){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return right;
    }
};