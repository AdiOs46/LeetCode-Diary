class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis = grid;
        queue<pair<int, int>> q;
        int countf = 0, minutes=0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j] == 2) q.push({i, j});
                if(vis[i][j] == 1) countf++;
            }
        }

        if(countf == 0) return 0;

        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == 1) {
                        vis[nx][ny] = 2;
                        countf--;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }
        if(countf == 0) return minutes-1;
        return -1;
    }
};
