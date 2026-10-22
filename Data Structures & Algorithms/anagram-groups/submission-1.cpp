class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key = array with chars
        // value = list of strings with "key" map
        map<array<int, 26>, vector<string>> counters;
        
        for (auto& s: strs) {
            array<int, 26> counter{};
            for (auto &c: s){
                counter[c - 'a']++;
            }
            counters[counter].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(counters.size());
        for (auto &[k, v]: counters){
            result.push_back(std::move(v));
        }
        return result;
    }
};
