#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = nums[0];
        int sum_thus_far = 0;
        
        for(auto n : nums) {
            sum_thus_far += n;
            if(sum_thus_far > max_sum)
                max_sum = sum_thus_far;
            
            if(sum_thus_far < 0)
                sum_thus_far = 0;
        }
        
        return max_sum;
    }
};