class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_count;
        for (auto& ch: t){
            t_count[ch]++;
        }

        unordered_map<char, int> s_count;
        int start_pos = -1, min_len = INT_MAX, l = 0, needed = 0;
        for (int r = 0; r < s.size(); ++r) {
            s_count[s[r]]++;
            if (t_count.contains(s[r]) && t_count[s[r]] >= s_count[s[r]]) {
                needed++;
            }
            while (t.size() == needed) {
                int win_len = r - l + 1;
                if ( win_len < min_len ) {
                    min_len = win_len;
                    start_pos = l;
                }

                s_count[s[l]]--;
                if (t_count.contains(s[l]) && t_count[s[l]] > s_count[s[l]]) {
                    needed--;
                }
                l++;
            }
        }
        return start_pos < 0 ? "" : s.substr(start_pos, min_len);
    }
};
