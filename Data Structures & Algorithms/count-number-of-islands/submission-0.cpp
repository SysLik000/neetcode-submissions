class Solution {
private:
    void visitIsland(vector<vector<char>>& grid, int r, int c){
        if (r < 0 || r >= grid.size())
            return;
        if (c < 0 || c >= grid[r].size())
            return;
        if (grid[r][c] != '1')
            return;
        grid[r][c] = '#';
        visitIsland(grid, r + 1, c);
        visitIsland(grid, r - 1, c);
        visitIsland(grid, r, c + 1);
        visitIsland(grid, r, c - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[r].size(); ++c){
                if (grid[r][c] == '1') {
                    visitIsland(grid, r, c);
                    ++count;
                }
            }
        }
        return count;
    }
};
