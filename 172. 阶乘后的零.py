# -*- encoding: utf-8 -*-


class Solution:
    def trailingZeroes(self, n: int) -> int:
        tmp = 1
        ans = 0
        while(tmp * 5 <= n):
            tmp *= 5
            ans += n // tmp
        return ans