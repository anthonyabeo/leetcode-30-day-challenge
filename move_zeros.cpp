#include <vector>
#include <queue>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::queue<int> q;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) q.push(i);
            else {
                if(!q.empty()) {
                    auto j = q.front(); q.pop();
                    auto temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;

                    q.push(i);
                }
            }
        }
    }
};