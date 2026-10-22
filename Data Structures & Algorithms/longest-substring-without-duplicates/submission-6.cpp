class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int l = 0, r = 0, length = 0;
        for (; r < s.size(); ++r){
            if (unique.contains(s[r])){
                for( ;unique.contains(s[r]); ++l )
                    unique.erase(s[l]);
            }
            unique.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return length;
    }
};
