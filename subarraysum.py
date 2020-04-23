"""
https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
"""

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cur_sum = 0
        count = 0
        prev_sum = {}
        
        for n in nums:
            cur_sum += n
            
            if cur_sum == k:
                count += 1
                
            if (cur_sum - k) in prev_sum:
                count += prev_sum[cur_sum - k]
            if cur_sum not in prev_sum:
                prev_sum[cur_sum] = 1
            else:
                prev_sum[cur_sum] += 1
                
        return count