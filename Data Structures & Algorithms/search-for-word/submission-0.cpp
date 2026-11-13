class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (checkWord(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool checkWord(vector<vector<char>>& board, string& word, int r, int c, int i){
        if (i == word.size())
            return true;
        if (r < 0 || r >= board.size())
            return false;
        if (c < 0 || c >= board[0].size() || board[r][c] != word[i]){
            return false;
        }
        board[r][c] = '#';
        bool res = checkWord(board, word, r + 1, c, i + 1) || 
        checkWord(board, word, r - 1, c, i + 1) || 
        checkWord(board, word, r, c + 1, i + 1) || 
        checkWord(board, word, r, c - 1, i + 1);
        board[r][c] = word[i];
        return res;
    }
};
