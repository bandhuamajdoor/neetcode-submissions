class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m;++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
    
        int time = 0;
        while(!q.empty()){
            int x = q.size();
            while(x--){
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nr < m
                    && nc >= 0 && nc < n
                    && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        
            if(!q.empty()) time++;
        }
    
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
    
        return time;
    }
};
