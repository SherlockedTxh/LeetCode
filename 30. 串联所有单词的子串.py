# -*- encoding: utf-8 -*-
from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        if not s or not words:
            return ans
        k = len(words[0])
        all_len = len(words) * k
        dic = Counter(words)
        for i in range(0, len(s) - all_len + 1):
            tmp = s[i:i+all_len]
            dictmp = []
            for j in range(0, all_len, k):
                dictmp.append(tmp[j:j+k])
            if Counter(dictmp) == dic:
                ans.append(i)
        return ans