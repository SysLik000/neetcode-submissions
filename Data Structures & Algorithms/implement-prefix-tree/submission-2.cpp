class PrefixTree {
private:
    struct Node{
        bool isEnd = false;
        std::unordered_map<char, Node*> children;
    };

    Node root;

    Node* findLastNode(string& word) {
        Node* cur = &root;
        for(auto& c: word){
            if(!cur->children[c]){
                return nullptr;
            }
            cur = cur->children[c];
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
                cur->children[c] = new Node();
            }
            cur = cur->children[c];
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
