class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        set<int> sorted(nums.begin(), nums.end());
        int result = 1, cur_len = 1;
        auto last = sorted.end();
        --last;
        for(auto it = sorted.begin(); it != last;){
            auto cur = it++;
            if (*it - *cur == 1) {
                ++cur_len;
                result = cur_len > result ? cur_len : result;
            } else {
                cur_len = 1;
            }
        }
        return result;
    }
};
