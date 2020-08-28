# -*- encoding: utf-8 -*-
from collections import OrderedDict

# 素数筛法
class Solution:
    def countPrimes(self, n: int) -> int:
        if(n < 2):
            return 0
        isPrime = [1] * n
        isPrime[0], isPrime[1] = 0, 1

        for i in range(2, int(n ** 0.5) + 1):
            if(isPrime[i]):
                isPrime[i * 2 : n : i] = [0] * len(isPrime[i * 2 : n : i])
        return sum(isPrime) - 1

class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n, 1);
        int cnt = 0;
        for(long long i = 2; i < n; i ++){
            if(!prime[i]) continue;
            cnt++;
            for(long long j = i * i; j < n; j += i){
                prime[j] = 0;
            }
        }
        return cnt;
    }
};
