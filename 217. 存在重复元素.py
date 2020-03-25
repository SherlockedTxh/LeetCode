# -*- encoding: utf-8 -*-

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dic = {}
        for num in nums:
            if num not in dic:
                dic[num] = 1
            else:
                return True
        return False