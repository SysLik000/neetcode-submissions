class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        vector<int> sizes(n, 1);
        std::iota(parents.begin(), parents.end(), 0);

        auto getParent = [&parents](int v){
            while (parents[v] != v){
                parents[v] = parents[parents[v]];
                v = parents[v];
            }
            return v;
        };

        for(const auto& edge: edges){
            int p0 = getParent(edge[0]), p1 = getParent(edge[1]);
            if (p0 == p1)
                continue;
            if (sizes[p0] < sizes[p1])
                swap(p0, p1);
            parents[p1] = p0;
            sizes[p0] += sizes[p1];
            n--;
        }

        return n;
    }
};
