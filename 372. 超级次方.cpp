#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        int last = b.back();
        b.pop_back();

        int part1 = mypow(a, last, 1337);
        int part2 = mypow(superPow(a, b), 10, 1337);
        return (part1 * part2) % 1337;
    }
    
    // 快速幂取模
    int mypow(int a, int b, int base){
        int ans = 1;
        a %= base;
        while(b){
            if(b & 1) ans = (ans * a) % base;
            a = (a * a) % base;
            b >>= 1;
        }
        return ans;
    }
};
