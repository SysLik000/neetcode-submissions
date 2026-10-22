class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> unique (nums.begin(), nums.end());
        return nums.size() != unique.size();
    }
};