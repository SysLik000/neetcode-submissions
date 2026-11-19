class Solution {
private:
    static constexpr array<pair<int, int>, 4> directions = {{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};

    void climb(queue<pair<int, int>>& q, const vector<vector<int>>& heights, vector<vector<bool>>& picks){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto [dr, dc]: directions){
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[nr].size()
                        && !picks[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                    picks[nr][nc] = true;
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

        auto add = [](queue<pair<int, int>>& q, vector<vector<bool>>& picks, int r, int c) {
            q.push({r, c});
            picks[r][c] = true;
        };

        for(int r = 0; r < rows; ++r){
            add(qPacific, pacificPicks, r, 0);
            add(qAtlantic, atlanticPicks, r, cols - 1);
        }

        for(int c = 0; c < cols; ++c ){
            add(qPacific, pacificPicks, 0, c);
            add(qAtlantic, atlanticPicks, rows - 1, c);
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
