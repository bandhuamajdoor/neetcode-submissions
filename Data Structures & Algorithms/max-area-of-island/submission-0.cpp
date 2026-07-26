class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(i < 0 || i >= grid.size()) return 0;
        if(j < 0 || j >= grid[0].size()) return 0;

        if(grid[i][j] == 0) return 0;
        if(visited[i][j]) return 0;

        visited[i][j] = true;

        int left = 1 + dfs(i, j - 1, grid, visited);
        int right = 1 + dfs(i, j + 1, grid, visited);
        int down = 1 + dfs(i + 1, j, grid, visited);
        int up = 1 + dfs(i - 1, j, grid, visited);


        return (left + right + down + up);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxi = 0;


        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j] && grid[i][j] == 1){
                    maxi = max(maxi, dfs(i, j, grid, visited));
                }
            }
        }
    
        return maxi/4;
    }
};
