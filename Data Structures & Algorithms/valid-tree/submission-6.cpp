class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((n - 1) != edges.size()){
            return false;
        }
        vector<int> parents(n);
        vector<int> sizes(n, 1);
        
        for(int i = 0; i < n; ++i){
            parents[i] = i;
        }

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
                return false;
            if (sizes[p0] < sizes[p1])
                swap(p0, p1);
            parents[p1] = p0;
            sizes[p0] += sizes[p1];
        }

        return true;
    }
};
