class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lengths;
        int result = 0;
        for(auto n: nums){
            if (!lengths[n]){
                lengths[n] = lengths[n - 1] + lengths[n + 1] + 1;
                lengths[n - lengths[n - 1]] = lengths[n];
                lengths[n + lengths[n + 1]] = lengths[n];
                result = max(result, lengths[n]);
            }
        }
        return result;
    }
};
