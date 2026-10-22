class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while( l < r ){
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int shift = l;
        l = 0, r = nums.size() - 1;
        while( l <= r ){
            int mid = (l + r) / 2;
            int id = (mid + shift) % nums.size();
            if (nums[id] == target)
                return id;
            if (nums[id] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;        
    }
};
