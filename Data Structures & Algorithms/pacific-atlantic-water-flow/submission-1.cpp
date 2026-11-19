class Solution {
private:
    char checkOceans(vector<vector<int>>& heights, int r, int c, int preH){
        if (r < 0 || c < 0)
            return 1;
        
        if (r >= heights.size() || c >= heights[r].size())
            return 2;
        
        if (heights[r][c] > preH)
            return 0;

        int curH = heights[r][c];
        heights[r][c] = INT_MAX;
        char res = checkOceans(heights, r - 1, c, curH) | checkOceans(heights, r, c - 1, curH) |
        checkOceans(heights, r + 1, c, curH) | checkOceans(heights, r, c + 1, curH);
        heights[r][c] = curH;

        return res;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        for(int r = 0; r < heights.size(); ++r){
            for(int c = 0; c < heights[r].size(); ++c){
                if (checkOceans(heights, r, c, INT_MAX) == 3){
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
