class Solution {
private:
    struct Node {
        int wordId = -1;
        int counter = 0;
        std::array<std::unique_ptr<Node>, 26> children;

        void addWord(const string &word, const int i) {
            Node* node = this;
            for(auto& c: word){
                auto & child = node->children[c - 'a'];
                if(!child)
                    child = std::make_unique<Node>();
                child->counter++;
                node = child.get();
            }
            node->wordId = i;
        }
    };

    int findWords(vector<vector<char>>& board, const vector<string>& words, Node* node, int r, int c, vector<string>& result){
        if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size())
            return 0;
        
        char ch = board[r][c];
        if (ch == '#')
            return 0;

        auto &child = node->children[ch - 'a'];
        if (!child || child->counter == 0)
            return 0;

        Node* next = child.get();
        int found = 0;
        if (next->wordId != -1){
            result.push_back(words[next->wordId]);
            next->wordId = -1;
            found++;
        }
        
        board[r][c] = '#';
        if (found < next->counter)
            found += findWords(board, words, next, r + 1, c, result);
        if (found < next->counter)
            found += findWords(board, words, next, r - 1, c, result);
        if (found < next->counter)
            found += findWords(board, words, next, r, c + 1, result);
        if (found < next->counter)
            found += findWords(board, words, next, r, c - 1, result);
        board[r][c] = ch;
        next->counter -= found;

        return found;
    }

    vector<string> getWords(vector<vector<char>>& board, const vector<string>& words, Node* root){
        vector<string> result;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j) {
                findWords(board, words, root, i, j, result);
                if (result.size() == words.size())
                    return result;
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