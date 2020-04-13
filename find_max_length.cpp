#include <vector>
#include <map>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums){
        int max_length = 0;
        int cnt = 0;
        std::map<int, int> m;
        m.insert({0, -1});
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) cnt++;
            else cnt--;
            
            if(m.count(cnt) == 1) 
                max_length = std::max(max_length, i - m.at(cnt));
            else 
                m.insert({cnt, i});
        }
        
        return max_length;
    }
    
    int findMaxLengthBruteForce(vector<int>& nums) {
        int max_length = 0;
        
        for(size_t i = 0; i < nums.size(); ++i) {
            int num_of_zeros = 0;
            int num_of_ones = 0;
            
            if(nums[i] == 0) num_of_zeros++;
            else num_of_ones++;
            
            for(size_t j = i+1; j < nums.size(); ++j) {
                if(nums[j] == 1) num_of_ones++;
                else num_of_zeros++;
                
                if(num_of_zeros == num_of_ones)
                    max_length = std::max(max_length, num_of_zeros+num_of_ones);
            }       
        }
        
        return max_length;
    }