class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = float('inf')
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                num = nums[i] + nums[left] + nums[right]
                if abs(ans - target) > abs(num - target):
                    ans = num
                if num < target:
                    left += 1
                elif num > target:
                    right -= 1
                else :
                    break
        return ans