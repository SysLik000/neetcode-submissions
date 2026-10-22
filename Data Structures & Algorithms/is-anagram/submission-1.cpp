class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, int> s_counter, t_counter;
        for (int i = 0; i < s.length(); ++i){
                s_counter[s[i]]++;
                t_counter[t[i]]++;
        }
        return t_counter == s_counter;
    }
};
