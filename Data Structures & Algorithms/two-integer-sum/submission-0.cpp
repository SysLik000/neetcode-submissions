class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            int v = target - nums[i];
            if (m.contains(v)) {
                return {m[v], i};
            } else {
                m[nums[i]] = i;
            };
        }
        return {};
    }
};
