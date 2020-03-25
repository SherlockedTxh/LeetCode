# -*- encoding: utf-8 -*-

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        dic = {}
        for i in range(0, len(s)):
            if s[i] not in dic:
                dic[s[i]] = 1
            else:
                dic[s[i]] += 1
            if t[i] not in dic:
                dic[t[i]] = -1
            else:
                dic[t[i]] -= 1
        for value in dic.values():
            if value != 0:
                return False
        return True