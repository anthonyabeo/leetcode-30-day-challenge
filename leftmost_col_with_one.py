# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        s = set()
        ROWS, COLS = binaryMatrix.dimensions()

        for r in range(0, ROWS):
            low = 0
            high = COLS - 1
            while low <= high:
                mid = low + ((high - low) // 2)  
                val = binaryMatrix.get(r, mid)
                if val == 0:
                    low = mid+1
                if val == 1:
                    if mid == 0: 
                        s.add(mid)
                        break
                    if mid-1 >= 0 and binaryMatrix.get(r, mid-1) == 0: 
                        s.add(mid)
                        break
                    high = mid-1
            
        return -1 if len(s) == 0 else min(s)