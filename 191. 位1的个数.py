# -*- encoding: utf-8 -*-


# 方法 1：循环和位移动
class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        mask = 1
        for i in range(0,32):
            if n & mask:
                cnt += 1
            mask << 1
        return cnt

# 将 n 和 n−1 做与运算，会把最后一个 1 的位变成 0 
class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while(n != 0):
            n &= (n - 1)
            cnt += 1
        return cnt