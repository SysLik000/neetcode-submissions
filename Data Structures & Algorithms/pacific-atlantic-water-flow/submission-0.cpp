class Solution {
private:
    bool bothOcean(vector<vector<int>>& heights, int r, int c, int preH){
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[r].size())
            return false;
        
        if (heights[r][c] > preH)
            return false;

        int curH = heights[r][c];
        bool toPacific  = bothOcean(heights, r - 1, c, curH) || bothOcean(heights, r, c - 1, curH);
        bool toAtlantic = bothOcean(heights, r + 1, c, curH) || bothOcean(heights, r, c + 1, curH);

        return true;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        for(int r = 0; r < heights.size(); ++r){
            for(int c = 0; c < heights[r].size(); ++c){
                if (bothOcean(heights, r, c, INT_MAX)){
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
