class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        std::sort(nums.begin(), nums.end());
        set<array<int, 3>> deduplicator;
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); ++i){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    array<int, 3> candidate = {nums[i], nums[j], nums[k]};
                    if (!deduplicator.contains(candidate)){
                        deduplicator.insert(candidate);
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                    ++j;
                    --k;
                }
                if (sum < 0)
                    ++j;
                else if (sum > 0)
                    --k;
            }
        }
        return result;
    }
};
