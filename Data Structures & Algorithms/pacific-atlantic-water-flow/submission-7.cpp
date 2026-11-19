class Solution {
private:
    static constexpr array<pair<int, int>, 4> directions = {{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};

    void addPick(queue<pair<int, int>>& q, vector<vector<bool>>& picks, int r, int c){
        if (picks[r][c])
            return;
        q.push({r, c});
        picks[r][c] = true;
    }

    void climb(queue<pair<int, int>>& q, const vector<vector<int>>& heights, vector<vector<bool>>& picks){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto [dr, dc]: directions){
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[nr].size()
                        && heights[nr][nc] >= heights[r][c]) {
                    addPick(q, picks, nr, nc);
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int, int>> qPacific, qAtlantic;

        vector<vector<bool>> pacificPicks(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticPicks(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; ++r){
            addPick(qPacific, pacificPicks, r, 0);
            addPick(qAtlantic, atlanticPicks, r, cols - 1);
        }

        for(int c = 0; c < cols; ++c ){
            addPick(qPacific, pacificPicks, 0, c);
            addPick(qAtlantic, atlanticPicks, rows - 1, c);
        }

        climb(qPacific, heights, pacificPicks);
        climb(qAtlantic, heights, atlanticPicks);
        
        vector<vector<int>> res;
        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                if (pacificPicks[r][c] && atlanticPicks[r][c]){
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
