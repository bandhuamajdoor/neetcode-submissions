int dr[] = {-1,1,0,0};
int dc[] = {0,0,1,-1};
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
        vector<vector<bool>>& visited, int& ans){
        if(visited[i][j]) return;
        visited[i][j] = true;

        for(int k = 0; k < 4; ++k){
            int r = i + dr[k];
            int c = j + dc[k];

            if(r < 0 || r >= grid.size()
            || c < 0 || c >= grid[0].size()){
                ans++;
                continue;
            }
            if(grid[r][c] == 0){
                ans++;
            }else{
                dfs(r, c, grid, visited, ans);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid, visited, ans);
                    return ans;
                }
            }
        }
        return -1;
    }
};