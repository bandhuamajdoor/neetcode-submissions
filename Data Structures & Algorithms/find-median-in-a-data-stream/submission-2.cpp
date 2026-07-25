class MedianFinder {
public:
int size;
priority_queue<int> smaller; // max heap
priority_queue<int, vector<int>, greater<int>> larger;  // min heap 

    MedianFinder() {
        this -> size = 0;
    }
    
    void addNum(int num) {
        size++;
        if(smaller.empty() || smaller.top() <= num) 
        {
            larger.push(num);
            if(larger.size() - smaller.size() > 1){
                smaller.push(larger.top());
                larger.pop();
            }
        }else{
            smaller.push(num);
            if(smaller.size() - larger.size() > 0){
                larger.push(smaller.top());
                smaller.pop();
            }
        }
    }
    
    double findMedian() {
        if(size % 2 == 0){
            return (smaller.top() + larger.top() + 0LL) / 2.0;
        }else{
            return larger.top() / 1.0;
        }
    }
};
