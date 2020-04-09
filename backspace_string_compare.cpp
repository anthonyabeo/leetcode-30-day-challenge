#include <stack>

class Solution {
public:
    bool backspaceCompare(std::string S, std::string T) {
        return magic(S) == magic(T);
    }
    
    string magic(std::string str) {
        std::stack<char> stk;
        
        for(char c : str) {
            if(c != '#') stk.push(c);
            else {
                if(!stk.empty()) stk.pop();
            }
        }
            
        string s;
        while(!stk.empty() && stk.top() != '#') {
            s.push_back(stk.top());
            stk.pop();
        } 
        
        return s;
    }
};