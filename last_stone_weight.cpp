#include <algorithm>
#include <vector>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;
        for(int x : stones)
            pq.push(x);
        
        while(pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            if(first != second)
                pq.push(std::abs(first - second));
        }
        
        if(pq.empty()) return 0;
        return pq.top();
    }
};