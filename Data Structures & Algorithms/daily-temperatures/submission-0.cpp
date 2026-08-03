class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for(int i = n - 1; i >= 0; --i){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
        
            if(!st.empty()) nge[i] = st.top();
            else nge[i] = -1;
            st.push(i);
        }
    
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i){
            ans[i] = nge[i] == -1 ? 0 : nge[i] - i;
        }
    
        return ans;
    }
};
