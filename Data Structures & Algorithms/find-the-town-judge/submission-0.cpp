class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(n + 1, 0);
        for(const auto& t: trust){
            adjList[t[0]].push_back(t[1]);
            indegree[t[1]]++;
        }

        for(int i = 1; i <= n; ++i){
            if(indegree[i] == n - 1 && adjList[i].size() == 0){
                return i;
            }
        }
    
        return -1;
    }
};