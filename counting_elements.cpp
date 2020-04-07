#include <multiset>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countElements(std::vector<int>& arr) {
        int count = 0;
        std::multiset<int> nums;
        std::multiset<int> plus_one;
        
        for(int e : arr) {
            nums.insert(e);
            plus_one.insert(e+1);
        }
        
        for(int e : plus_one) {
            if(nums.count(e) > 0) 
                count++;
        }
        
        return count;
    }

    int altCountElements(vector<int>& arr) {
        int count = 0;
        std::sort(arr.begin(), arr.end());
        
        for(int e : arr) {
            if(std::binary_search(arr.begin(), arr.end(), e+1))
               count++;
        }
               
        return count;
    }
};