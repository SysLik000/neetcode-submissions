class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_counter, t_counter;
        for (const auto & c: s){
            if (s_counter.contains(c)){
                s_counter[c] += 1;
            } else {
                s_counter[c] = 1;
            }
        }
        for (const auto & c: t){
            if (t_counter.contains(c)){
                t_counter[c] += 1;
            } else {
                t_counter[c] = 1;
            }
        }
        return t_counter == s_counter;
    }
};
