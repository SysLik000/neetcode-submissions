class Solution {
private:
    struct Node {
        int wordId = -1;
        bool isEnd = false;
        std::unordered_map<char, std::unique_ptr<Node>> children;

        void addWord(const string &word, int id) {
            Node* node = this;
            for(auto& c: word){
                auto& child = node->children[c];
                if(!child){
                    child = std::make_unique<Node>();
                }
                node = child.get();
            }
            node->isEnd = true;
            node->wordId = id;
        }
    };

    void findWords(vector<vector<char>>& board, vector<string>& words, Node* node, int r, int c, vector<string>& result){
        if (r < 0 || r >= board.size())
            return;
        if (c < 0 || c >= board[0].size())
            return;
        
        char ch = board[r][c];
        auto child = node->children.find(ch);
        if (ch == '#' || child == node->children.end())
            return;

        node = child->second.get();
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

    vector<string> getWords(vector<vector<char>>& board, vector<string>& words, Node* root){
        vector<string> result;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j) {
                findWords(board, words, root, i, j, result);
            }
        }
        return result;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node root;
        for(int i = 0; i < words.size(); ++i){
            root.addWord(words[i], i);
        }
        return getWords(board, words, &root);
    }
};