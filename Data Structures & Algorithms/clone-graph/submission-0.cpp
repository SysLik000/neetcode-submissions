/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        std::unordered_map<Node*, Node*> old_new;
        old_new[node] = new Node(node->val);
        std:queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto n: cur->neighbors){
                if (old_new[n] == nullptr){
                    old_new[n] = new Node(n->val);
                    q.push(n);
                }
                old_new[cur]->neighbors.push_back(old_new[n]);
                
            }
        }

        return old_new[node];
    }
};
