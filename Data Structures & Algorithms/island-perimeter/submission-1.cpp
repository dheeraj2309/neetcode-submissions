class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        queue<pair<int,int>>q;
        bool flag = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    q.push({i,j});
                    grid[i][j] = -1;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k],nc = c + dc[k];
                // if nr and nc cross grid , then one edge 
                if(nr  < 0 || nr >= m || nc < 0 || nc >= n){
                    cnt++;
                    continue;
                } 
                if(nr >= 0 && nr < m &&  nc >= 0 && nc < n && grid[nr][nc] != -1){
                    if(grid[nr][nc] == 0) cnt++;
                    else{
                        q.push({nr,nc});
                        grid[nr][nc] = -1;
                    }
                }
            }
            // grid[r][c] = -1;
        }
        return cnt;
    }
};