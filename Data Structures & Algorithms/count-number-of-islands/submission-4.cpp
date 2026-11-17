class Solution {
private:
    static constexpr array<pair<int,int>, 4> directions = {{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};

    inline bool isLand(const vector<vector<char>>& grid, int r, int c){
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] == '1';
    }

    void visitIsland(vector<vector<char>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '#';
        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(const auto&[rd, cd]: directions){
                int nr = r + rd;
                int nc = c + cd;
                if (isLand(grid, nr, nc)){
                    grid[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[r].size(); ++c){
                if (isLand(grid, r, c)) {
                    visitIsland(grid, r, c);
                    ++count;
                }
            }
        }
        return count;
    }
};
