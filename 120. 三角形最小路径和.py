from typing import List
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        ans = triangle[-1]
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                ans[j] = triangle[i][j] + min(ans[j], ans[j + 1])
        return ans[0]