class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times) 
            adj[it[0]].push_back({it[1], it[2]});
        
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int curr_time = curr.first;
            int curr_node = curr.second;

            for(auto it : adj[curr_node]) {
                int next_node = it.first;
                int next_time = it.second;
                if(next_time + curr_time < dist[next_node]) {
                    dist[next_node] = next_time + curr_time;
                    pq.push({next_time + curr_time, next_node});
                }
            } 
        }

        int max_time = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) 
                return -1;
            max_time = max(dist[i], max_time);
        }
        return max_time;              
    }
};
