class Solution {
private:
    struct Node {
        int wordId = -1;
        std::array<std::unique_ptr<Node>, 26> children;

        void addWord(const string &word, const int i) {
            Node* node = this;
            for(auto& c: word){
                int id = c - 'a';
                if(!node->children[id]){
                    node->children[id] = std::make_unique<Node>();
                }
                node = node->children[id].get();
            }
            node->wordId = i;
        }
    };

    void findWords(vector<vector<char>>& board, const vector<string>& words, Node* node, int r, int c, vector<string>& result){
        if (r < 0 || r >= board.size())
            return;
        if (c < 0 || c >= board[r].size())
            return;
        
        char ch = board[r][c];
        int id = ch - 'a';
        if (ch == '#' || !node->children[id])
            return;

        node = node->children[id].get();
        if (node->wordId != -1){
            result.push_back(words[node->wordId]);
            node->wordId = -1;
        }

        board[r][c] = '#';
        findWords(board, words, node, r + 1, c, result);
        findWords(board, words, node, r - 1, c, result);
        findWords(board, words, node, r, c + 1, result);
        findWords(board, words, node, r, c - 1, result);
        board[r][c] = ch;
    }

    vector<string> getWords(vector<vector<char>>& board, const vector<string>& words, Node* root){
        vector<string> result;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j) {
                findWords(board, words, root, i, j, result);
            }
        }
        return result;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        Node root;
        for(int i = 0; i < words.size(); ++i){
            root.addWord(words[i], i);
        }
        return getWords(board, words, &root);
    }
};