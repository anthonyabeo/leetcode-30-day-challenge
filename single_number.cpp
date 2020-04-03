#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int s = 0;
        for(auto n : nums) {
            s ^= n;
        }
        
        return s;
    }
};