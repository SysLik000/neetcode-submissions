class WordDictionary {
private:
    struct Node{
        bool isEnd = false;
        std::array<std::unique_ptr<Node>, 26> children;
    };

    Node root;

    bool searchWord(Node* node, const string &word, int i) {
        for(;i < word.size(); ++i){
            if (word[i] == '.'){
                for(auto& child: node->children){
                    if (child && searchWord(child.get(), word, i + 1)){
                        return true;
                    }
                }
                return false;
            }
            int id = word[i] - 'a';
            if(!node->children[id]){
                return false;
            }
            node = node->children[id].get();
        }
        return node->isEnd;
    }

public:
    WordDictionary() {       
    }
    
    void addWord(const string &word) {
        Node* cur = &root;
        for(auto& c: word){
            int id = c - 'a';
            if(!cur->children[id]){
                cur->children[id] = std::make_unique<Node>();
            }
            cur = cur->children[id].get();
        }
        cur->isEnd = true;
    }
    
    bool search(const string &word) {
        return searchWord(&root, word, 0);
    }
};
