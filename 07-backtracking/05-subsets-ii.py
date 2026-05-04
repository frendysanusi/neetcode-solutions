class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(i: int, curr: List[int]):
            if i == len(nums):
                if curr[:] not in res:
                    res.append(curr[:])
                return
            
            curr.append(nums[i])
            backtrack(i + 1, curr)
            curr.pop()

            while i + 1 < len(nums) and nums[i + 1] == nums[i]:
                i += 1

            backtrack(i + 1, curr)
        
        backtrack(0, [])
        return res