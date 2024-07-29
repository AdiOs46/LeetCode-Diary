class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dir = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int curr_dist = node.first;
            int x = node.second.first;
            int y = node.second.second;

            if (x == n - 1 && y == m - 1) return curr_dist;

            for(auto it : dir) {
                int nx = x + it[0];
                int ny = y + it[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m)  {
                    int newEffort = max(abs(heights[x][y] - heights[nx][ny]), curr_dist);
                    if(newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                } 
            }
        } 
        return 0;
    }
};
