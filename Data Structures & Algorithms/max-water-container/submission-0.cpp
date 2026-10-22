class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0, i = 0, j = heights.size() - 1;
        while (i < j){
            int v = (j - i);
            if (heights[i] < heights[j]){
                v *= heights[i];
                ++i;
            } else {
                v *= heights[j];
                --j;
            }
            result = max(result, v);
        }
        return result;
    }
};