class Solution {
public:
    bool isValid(string s) {
        stack<char> opens;
        for(auto& c: s) {
            if (c == '(' || c == '{' || c == '[') {
                opens.push(c);
            } else {
                if (opens.empty())
                    return false;
                char op = opens.top();
                if (   (c == ')' && op != '(')
                    || (c == '}' && op != '{')
                    || (c == ']' && op != '['))
                {
                    return false;
                }
                opens.pop();
            }
        }
        return opens.empty();
    }
};
