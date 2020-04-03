#include <set>

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> s;
        s.insert(n);

        int m, a;
        
        while(n != 1) {
            m = 0;
            while(n > 0) {
                a = n % 10;
                m += a*a;
                n /= 10;
            }
            
            if (s.find(m) != s.end()) return false;
            else s.insert(m);
            
            n = m;
        }
        
        return true;
    }
};