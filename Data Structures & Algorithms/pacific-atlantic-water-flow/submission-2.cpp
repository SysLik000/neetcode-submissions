class Solution {
private:
    static constexpr array<pair<int, int>, 4> directions = {{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};

    void climb(queue<pair<int, int>>& q, vector<vector<int>>& heights, vector<vector<bool>>& picks){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            picks[r][c] = true;
            for(auto [dr, dc]: directions){
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[r].size()
                    && !picks[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        queue<pair<int, int>> qPacific, qAtlantic;

        for(int r = 0; r < rows; ++r){
            qPacific.push({r, 0});
            qAtlantic.push({r, cols -1});
        }

        for(int c = 0; c < cols; ++c ){
            qPacific.push({0, c});
            qAtlantic.push({rows - 1, c});
        }

        vector<vector<bool>> pacificPicks(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticPicks(rows, vector<bool>(cols, false));;
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
