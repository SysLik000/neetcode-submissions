class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> requirements(numCourses);
        vector<int> dependents(numCourses, 0);
        for(auto &p: prerequisites){
            dependents[p[1]]++;
            requirements[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for(int i = 0; i < requirements.size(); ++i){
            if (dependents[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int no_dependents_node = q.front();
            q.pop();
            numCourses--;
            if (numCourses == 0)
                return true;
            for (int before: requirements[no_dependents_node]){
                dependents[before]--;
                if (dependents[before] == 0){
                    q.push(before);
                }
            }
        }
        return false;
    }
};
