# -*- encoding: utf-8 -*-

# 二分法
# 如果 nums[mid] > nums[mid + 1]，那么在mid右侧必有峰值，反之则在左侧
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left