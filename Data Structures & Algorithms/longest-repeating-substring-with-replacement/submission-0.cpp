class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, length = 0, result = 0;
        for (int r = 0; r < s.size(); ++r){
            count[s[r]]++;
            length = max(length, count[s[r]]);
            while( (r - l + 1) - length > k ){
                count[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};