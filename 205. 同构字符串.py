# -*- encoding: utf-8 -*-

# 没啥算法 需要实现一个通过value找key
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        def get_key (dict, value):
            return [k for k, v in dict.items() if v == value]

        if len(s) != len(t):
            return False
        dic = {}
        for i in range(0, len(s)):
            if s[i] in dic:
                if dic[s[i]] != t[i]:
                    return False
            elif get_key(dic, t[i]):
                return False
            dic[s[i]] = t[i]
        return True