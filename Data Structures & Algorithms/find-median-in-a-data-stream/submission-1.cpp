class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small.empty() || small.top() >= num){
            small.push(num);
        } else {
            big.push(num);
        }
        int size_diff = small.size() - big.size();
        if (size_diff > 1){
            big.push(small.top());
            small.pop();
        }
        if (size_diff < 0){
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == big.size())
            return double(small.top() + big.top()) / 2;
        return small.top();
    }
};
