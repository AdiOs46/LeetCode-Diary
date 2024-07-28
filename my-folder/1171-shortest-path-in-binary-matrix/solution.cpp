class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0] == 0 ? 1 : -1;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;

        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int dis = node.first;
            auto [x, y] = node.second;

            for(auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy; 
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && dis + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dis + 1;
                    if(nx == n-1 && ny == n-1) return dis+1;
                    q.push({dis+1, {nx, ny}});
                }
            }
        }
        return -1;
    }
};
