class WordDictionary {
private:
    struct Node{
        bool isEnd = false;
        std::unordered_map<char, std::unique_ptr<Node>> children;
    };

    Node root;

    bool searchWord(Node* node, const string &word, int i) {
        for(;i < word.size(); ++i){
            if (word[i] == '.'){
                for(auto& child: node->children){
                    if (searchWord(child.second.get(), word, i + 1)){
                        return true;
                    }
                }
                return false;
            }
            auto it = node->children.find(word[i]);
            if(it == node->children.end()){
                return false;
            }
            node = it->second.get();
        }
        return node->isEnd;
    }

public:
    WordDictionary() {       
    }
    
    void addWord(const string &word) {
        Node* node = &root;
        for(auto& c: word){
            auto& child = node->children[c];
            if(!child){
                child = std::make_unique<Node>();
            }
            node = child.get();
        }
        node->isEnd = true;
    }
    
    bool search(const string &word) {
        return searchWord(&root, word, 0);
    }
};
