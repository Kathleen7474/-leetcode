class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 0
        candidate = None
        for n in nums:
            if cnt == 0:
                candidate = n
            if candidate == n:
                cnt = cnt +1
            else:
                cnt = cnt -1
        return candidate
        
