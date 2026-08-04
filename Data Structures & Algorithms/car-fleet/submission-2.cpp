class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        int n = position.size();
        for(int i = 0; i < n; ++i){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        stack<double> st;

        for(int i = 0; i < n; ++i){
            double time = (double)(target - arr[i].first)/arr[i].second;

            if(st.empty() || st.top() < time){
                st.push(time);
            }
        }
    
        return st.size();
    }
};
