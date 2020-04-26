class Solution {
    public boolean canJump(int[] nums) {
        int furSoFar = 0, lastlndex = nums.length - 1;
        for (int i = 0; i <= furSoFar && furSoFar < lastlndex;++i) {
            furSoFar = Math.max(furSoFar , i + nums[i]);
        }
        
        return furSoFar >= lastlndex;
    }
}