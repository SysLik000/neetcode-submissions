class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        for(auto& n: nums){
            ++counter[n];
        }
        vector<vector<int>> frequency(nums.size() + 1);
        for(auto& [n, c]: counter){
            frequency[c].push_back(n);
        }
        vector<int> result;
        for(auto i = frequency.size() - 1; i > 0; --i){
            for(auto n: frequency[i]){
                result.push_back(n);
                if (result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
