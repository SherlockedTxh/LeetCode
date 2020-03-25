# -*- encoding: utf-8 -*-


class Solution:
    def titleToNumber(self, s: str) -> int:
        ans = 0
        for c in s:
            ans *= 26
            ans += ord(c) - ord('A') + 1
        return ans