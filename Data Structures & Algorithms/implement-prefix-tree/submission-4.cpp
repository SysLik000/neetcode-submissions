class PrefixTree {
private:
    struct Node{
        bool isEnd = false;
        std::unordered_map<char, std::unique_ptr<Node>> children;
    };

    Node root;

    Node* findLastNode(string& word) {
        Node* cur = &root;
        for(auto& c: word){
            auto it = cur->children.find(c);
            if(it == cur->children.end()){
                return nullptr;
            }
            cur = it->second.get();
        }
        return cur;
    }
public:
    PrefixTree() {
    }
    
    void insert(string& word) {
        Node* cur = &root;
        for(auto& c: word){
            if(!cur->children[c]){
                cur->children[c] = std::make_unique<Node>();
            }
            cur = cur->children[c].get();
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
