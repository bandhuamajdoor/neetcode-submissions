class Solution {
public:
    int distance(vector<int>& x){
        return ((x[0]*x[0]) + (x[1]*x[1]));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for(auto& point: points){
            pq.push({distance(point), {point[0], point[1]}});

            if(pq.size() > k) pq.pop();
        }
    
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = it.second.first;
            int y = it.second.second;

            
            ans.push_back({x, y});
        }
    
        return ans;
    }
};  
