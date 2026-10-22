class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> open{'(', '{', '['};
        unordered_set<string> valid_parentheses{"()", "{}", "[]"};
        stack<char> opens;
        for(auto& c: s) {
            if (open.contains(c)) {
                opens.push(c);
            } else {
                if (opens.empty()) {
                    return false;
                }
                string p{opens.top(), c};
                opens.pop();
                if (!valid_parentheses.contains(p)) {
                    return false;
                }
            }
        }
        return opens.empty();
    }
};
