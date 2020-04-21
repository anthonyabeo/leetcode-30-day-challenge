class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        
        size = len(nums)
        s = self.min_index(nums, low, high)
        
        while(low <= high):
            mid = low + (high - low) // 2

            if nums[indx(mid, size, s)] == target:
                return indx(mid, size, s)
            elif nums[indx(mid, size, s)] > target:
                high = mid-1
            else:
                low = mid+1

        return -1

    def min_index(self, arr, low, high):
        mid = int(low + (high - low)/2)

        if (high < low): return 0
        if (high == low): return low 

        if (arr[mid] < arr[mid-1]) and (arr[mid] < arr[mid+1]):
            return mid

        if arr[high] > arr[mid]:
            return self.min_index(arr, low, mid-1)

        return self.min_index(arr, mid+1, high)
    
def indx(i, size, s):
    return (i + s) % size