class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(n == 0) return -1;

        vector<pair<int, int>> adj[n];
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int curr_steps = curr.first;
            int node = curr.second.first;
            int curr_price= curr.second.second;
            
            if(curr_steps > k) continue;

            for(auto it : adj[node]) {
                int next_node = it.first;
                int next_price = it.second;

                if(next_price + curr_price < dist[next_node] && curr_steps <= k) {
                    dist[next_node] = next_price + curr_price;
                    pq.push({curr_steps+1, {next_node, next_price + curr_price}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
