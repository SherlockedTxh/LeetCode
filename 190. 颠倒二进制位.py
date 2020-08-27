# -*- encoding: utf-8 -*-

# n右移31-i得到的数字的最后一位是结果数字的第i位
class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(0, 32):
            ans += ((n >> (31 - i)) & 1) << i
        return ans

// 这个算法为用 3 个操作反转一个字节中的位
class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};
