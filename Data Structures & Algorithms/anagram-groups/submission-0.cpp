class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key = map with char count
        // value = list of strings with "key" map
        map<map<char, int>, vector<string>> counters;
        
        for (auto& s: strs) {
            map<char, int> counter;
            for (auto &c: s){
                counter[c]++;
            }
            counters[counter].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &[k, v]: counters){
            result.push_back(v);
        }
        return result;
    }
};
