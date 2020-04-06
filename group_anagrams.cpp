#include <vector>
#include <map>
#include <unordered_map>

class Solution {
public:
    vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::map<int, vector<string>> map;
        std::vector<vector<string>> result;
        
        std::hash<std::string> hasher;
        for(std::string s : strs) {
            auto st = s; std::sort(st.begin(), st.end()); 
            
            int hash = hasher(st);
            if(map.count(hash) == 1) {
                map.at(hash).push_back(s);
                continue;
            }
            
            std::vector<string> vec {s};
            map.insert({hash, vec});
        }
        
        for(const auto& x : map) {
            result.push_back(x.second);
        }
        
        return result;
    }
};
