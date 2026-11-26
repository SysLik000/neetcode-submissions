class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> map_bigger;
        unordered_map<char, unordered_set<char>> map_lower;
        for (const auto& w: words) {
            for(const char c: w){
                if (!map_bigger.contains(c)){
                    map_bigger[c] = unordered_set<char>();
                    map_lower[c] = unordered_set<char>();
                }
            }
        }

        for(int i = 0; i < words.size() - 1; ++i){
            const string& w1 = words[i], w2 = words[i + 1];
            int min_len = std::min(w1.size(), w2.size());
            if (w1.size() > min_len && w1.substr(0, min_len) == w2){
                return "";
            }
            for(int j = 0; j < min_len; ++j){
                if (w1[j] != w2[j]){
                    map_bigger[w1[j]].insert(w2[j]);
                    map_lower[w2[j]].insert(w1[j]);
                    break;
                }
            }
        }

        queue<char> q;
        for(auto &[c, lower]: map_lower){
            if (!lower.size()){
                q.push(c);
            }
        }

        string res;
        while (!q.empty()) {
            int lowest = q.front();
            q.pop();

            res += lowest;
            for (auto bigger: map_bigger[lowest]) {
                map_lower[bigger].erase(lowest);
                if (!map_lower[bigger].size()){
                    q.push(bigger);
                }
            }
        }

        return res.size() == map_lower.size() ? res : "";
    }
};