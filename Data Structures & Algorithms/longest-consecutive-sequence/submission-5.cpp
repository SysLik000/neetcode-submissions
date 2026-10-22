class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int result = 0;
        for(auto n: unique){
            if (unique.contains(n-1))
                continue;
            int len = 1;
            while (unique.contains(++n)){
                ++len;
            }
            result = max(result, len);
        }
        return result;
    }
};
