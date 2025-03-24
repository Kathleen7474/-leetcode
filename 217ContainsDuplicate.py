class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        arr = {}
        for n in nums:
            if n in arr:
                return True
            else:
                arr[n]= 1
        return False
