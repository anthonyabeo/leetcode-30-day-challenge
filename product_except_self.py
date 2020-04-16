class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out = [1] * len(nums) 
        
        prod_total = 1
        
        for i in range(0, len(out)):
            out[i] = prod_total
            prod_total *= nums[i]
   
        prod_total = 1
        
        for i in range(len(out)-1, -1, -1):
            out[i] *= prod_total
            prod_total *= nums[i]

        return out