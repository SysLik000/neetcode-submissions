template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T,U>& r, const std::pair<T,U>& l){
    return {r.first + l.first, r.second + l.second };
}

class Solution {
private:
    array<pair<int,int>, 4> directions = {{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }};
    void visitIsland(vector<vector<char>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            if (r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size() || grid[r][c] != '1')
                continue;
            grid[r][c] = '#';
            for(const auto& d: directions){
                q.push(pair<int, int>{r, c} + d);
            }
        }
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
