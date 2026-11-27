class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int left_2 = nums[0],
            left_1 = std::max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); ++i){
            int tmp = std::max(nums[i] + left_2, left_1);
            left_2 = left_1;
            left_1 = tmp;
        }
        return left_1;
    }
};
