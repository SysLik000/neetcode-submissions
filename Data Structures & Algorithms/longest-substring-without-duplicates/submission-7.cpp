class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> unique;
        int l = 0, length = 0;
        for (int r = 0; r < s.size(); ++r){
            if (unique.contains(s[r])){
                l = max(l, unique[s[r]] + 1);
            }
            unique[s[r]] = r;
            length = max(length, r - l + 1);
        }
        return length;
    }
};
