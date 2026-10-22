class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> closeOpen = {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };
        stack<char> opens;
        for(auto& c: s) {
            if (!closeOpen.contains(c)) {
                opens.push(c);
            } else {
                if (opens.empty())
                    return false;
                if (closeOpen[c] != opens.top()) {
                    return false;
                }
                opens.pop();
            }
        }
        return opens.empty();
    }
};
