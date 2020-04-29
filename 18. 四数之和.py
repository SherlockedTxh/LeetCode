# -*- encoding: utf-8 -*-
from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = set()
        n = len(nums)
        nums.sort()
        dic = {}

        for i in range(n):
            for j in range(i + 1, n):
                sum = nums[i] + nums[j]
                if target - sum in dic:
                    for tmp in dic[target - sum]:
                        if tmp[1] < i:
                            ans.add((nums[tmp[0]], nums[tmp[1]], nums[i], nums[j]))
                if sum not in dic:
                    dic[sum] = []
                dic[sum].append((i, j))
        
        res = []
        for tmp in ans:
            res.append(list(tmp))
        return res