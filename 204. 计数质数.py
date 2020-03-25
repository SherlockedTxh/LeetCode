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