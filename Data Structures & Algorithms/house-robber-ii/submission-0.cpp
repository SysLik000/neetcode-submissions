class Solution {
private:
    int rob_helper(std::vector<int>::iterator begin, std::vector<int>::iterator end){
        int left_2 = 0, left_1 = 0;

        for(auto it = begin; it < end; ++it){
            int tmp = std::max(*it + left_2, left_1);
            left_2 = left_1;
            left_1 = tmp;
        }
        return left_1;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        return std::max(rob_helper(nums.begin(), nums.end() - 1), rob_helper(nums.begin() + 1, nums.end()));
    }
};
