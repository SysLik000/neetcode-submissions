class Solution {
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> cur, int i, int target){
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int j = i; j < nums.size(); j++){
            if (target - nums[j] < 0) {
                return;
            }
            cur.push_back(nums[j]);
            backtrack(nums, cur, j, target - nums[j]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(nums, {}, 0, target);
        return res;
    }
};
