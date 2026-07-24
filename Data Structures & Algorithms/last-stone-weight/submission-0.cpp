class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        // max heap

        for(int w: stones){
            pq.push(w);
        }


        if(pq.size() < 2){
            return pq.top();
        }

        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = 0;
            if(!pq.empty()) second = pq.top();
            pq.pop();
            if(first != second){
                int remStone = first - second;
                pq.push(remStone);
            } 
        }
    
        return pq.size() == 0 ? 0 : pq.top();
    }
};
