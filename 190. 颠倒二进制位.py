# -*- encoding: utf-8 -*-
from collections import OrderedDict

# -*- encoding: utf-8 -*-
from collections import OrderedDict

# n右移31-i得到的数字的最后一位是结果数字的第i位
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(0, 32):
            ans += ((n >> (31 - i)) & 1) << i
        return ans