class Solution {
public:

    string encode(vector<string>& strs) {
        string r;
        for(auto& s: strs){
            r.append(to_string(s.size()));
            r.append("#");
            r.append(s);
        }
        return r;
    }

    vector<string> decode(string s) {
        vector<string> r;
        int i = 0, j = 0;
        while( i < s.size()){
            for (j = i; s[j] != '#'; ++j);
            int lenght = stoi(s.substr(i, j - i));
            r.push_back(s.substr(j + 1, lenght));
            i = j + 1 + lenght;
        }
        return r;
    }
};
