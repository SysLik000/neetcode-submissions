class PrefixTree {
private:
    struct Node{
        bool isEnd = false;
        std::array<std::unique_ptr<Node>, 26> children;
    };

    Node root;

    Node* findLastNode(string& word) {
        Node* cur = &root;
        for(auto& c: word){
            int id = c - 'a';
            if(!cur->children[id]){
                return nullptr;
            }
            cur = cur->children[id].get();
        }
        return cur;
    }
public:
    PrefixTree() {
    }
    
    void insert(string& word) {
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
    
    bool search(string& word) {
        Node* node = findLastNode(word);
        return node && node->isEnd;
    }
    
    bool startsWith(string& prefix) {
        return findLastNode(prefix) != nullptr;
    }
};
