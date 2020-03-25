# -*- encoding: utf-8 -*-

# 方法一 切片
# Note：如果使用nums = nums[lenth-k:]+nums[:lenth-k]，会错
# 这道题的线上判定取的是原nums的地址，如果不写切片，修改后的nums地址会指向右侧的临时地址，
# 虽然在函数内调用nums是正常的，但在线判定就无法AC，因为源地址的nums未被修改，写nums[:]则默认是在源地址上修改，所以才可以AC。
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ##用切片的方法：k就是将nums的最后k个数放在nums的开始位置即可
        lenth = len(nums)
        nums[:] = nums[lenth-k:]+nums[:lenth-k]

# 方法二：循环k次

# 方法三：另外开一个数组

# 方法四：使用环状替换
# https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode/
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        count = 0
        start = 0
        while(count < len(nums)):
            curr = start
            pre = nums[start]
            while(1):
                next = (curr + k) % len(nums)
                tmp = nums[next]
                nums[next] = pre
                pre = tmp
                curr = next
                count += 1
                if start == curr:
                    break
            start += 1

# 方法五：反转
# 这个方法基于这个事实：当我们旋转数组 k 次， k%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。
# 在这个方法中，我们首先将所有元素反转。然后反转前 k 个元素，再反转后面 n−k 个元素，就能得到想要的结果。
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= n
        nums.reverse() # nums[:] = nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]