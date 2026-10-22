class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0];
        int l = 0, r = nums.size() - 1;
        while( l <= r ){
            if (nums[l] < nums[r]){
                return min(result, nums[l]);
            }
            int mid = (l + r) / 2;
            result = min(result, nums[mid]);
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } 
        return result;
    }
};
