class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int INF = 2147483647;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
    
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            const auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int i = 0; i < 4; ++i){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(grid[nr][nc] == -1) continue;
                if(grid[nr][nc] != INF) continue;

                grid[nr][nc] = 1 + grid[r][c];
                q.push({nr, nc});
            }
        }
    }
};
