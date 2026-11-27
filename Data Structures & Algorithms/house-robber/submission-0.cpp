class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> amounts(nums.size());
        amounts[0] = nums[0];
        amounts[1] = std::max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); ++i){
            amounts[i] = std::max(nums[i] + amounts[i-2], amounts[i -1]);
        }
        return amounts[nums.size() - 1];
    }
};
