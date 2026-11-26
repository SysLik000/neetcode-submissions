class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> map_bigger;
        unordered_map<char, int> indegree;
        for (const auto& w: words) {
            for(const char c: w){
                if (map_bigger.count(c) == 0){
                    map_bigger[c] = unordered_set<char>();
                    indegree[c] = 0;
                }
            }
        }

        for(int i = 0; i < words.size() - 1; ++i){
            const string& w1 = words[i], w2 = words[i + 1];
            int min_len = std::min(w1.size(), w2.size());
            int j = 0;
            for(; j < min_len; ++j){
                if (w1[j] != w2[j]){
                    if (!map_bigger[w1[j]].contains(w2[j])){
                        map_bigger[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
            if (j == min_len && w1.size() > min_len)
                return "";
        }

        queue<char> q;
        for(auto &[c, degree]: indegree){
            if (degree == 0){
                q.push(c);
            }
        }

        string res;
        while (!q.empty()) {
            char lowest = q.front();
            q.pop();

            res += lowest;
            for (auto bigger: map_bigger[lowest]) {
                indegree[bigger]--;
                if (indegree[bigger] == 0){
                    q.push(bigger);
                }
            }
        }

        return res.size() == indegree.size() ? res : "";
    }
};