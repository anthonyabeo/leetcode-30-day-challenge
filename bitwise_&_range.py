"""
Reference

Ida (https://math.stackexchange.com/users/232620/ida), How to find Bitwise AND of all numbers for a given range?, URL (version: 2015-04-19): https://math.stackexchange.com/q/1241533
"""
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        shift = 0
        
        while m != n:
            m >>= 1 
            n >>= 1
            shift += 1
        
        return m << shift
        
            
        