class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty())
            return 0;

        priority_queue<int> q(stones.begin(), stones.end());
        while(q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a - b);
        }
        return q.top();
    }
};
