class Solution {
private:
    array<pair<int,int>, 4> directions = {{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};

    inline bool isIsland(vector<vector<char>>& grid, int r, int c){
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size() && grid[r][c] == '1';
    }

    inline void visit(vector<vector<char>>& grid, int r, int c){
        grid[r][c] = '#';
    }

    void visitIsland(vector<vector<char>>& grid, int row, int col){
        if (!isIsland(grid, row, col))
            return;
        queue<pair<int, int>> q;
        q.push({row, col});
        visit(grid, row, col);
        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(const auto&[rd, cd]: directions){
                int nr = r + rd;
                int nc = c + cd;
                if (isIsland(grid, nr, nc)){
                    visit(grid, nr, nc);
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
                if (isIsland(grid, r, c)) {
                    visitIsland(grid, r, c);
                    ++count;
                }
            }
        }
        return count;
    }
};
