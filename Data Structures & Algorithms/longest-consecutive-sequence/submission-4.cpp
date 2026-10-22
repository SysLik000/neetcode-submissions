class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lengths;
        int result = 0;
        for(auto n: nums){
            if (lengths[n])
                continue;
            int left = lengths[n - 1];
            int right = lengths[n + 1];
            int len = left + right + 1;
            lengths[n] = len;
            lengths[n - left] = len;
            lengths[n + right] = len;
            result = max(result, len);
        }
        return result;
    }
};
