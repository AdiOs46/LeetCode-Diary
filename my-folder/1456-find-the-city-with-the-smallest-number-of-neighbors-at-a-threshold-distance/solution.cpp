class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});  
        }
        vector<int> p_answers(n);
        int src = 0;
        while(src < n) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
            pq.push({0, src});

            while(!pq.empty()) {
                auto curr = pq.top();
                pq.pop();
                int curr_weight = curr.first;
                int curr_node = curr.second;

                for(auto it : adj[curr_node]) {
                    int next_node = it.first;
                    int next_weight = it.second;
                    if(curr_weight + next_weight < dist[next_node]) {
                        dist[next_node] = curr_weight + next_weight;
                        pq.push({curr_weight + next_weight, next_node});
                    }
                }
            }

            int count = 0;
            for(int i=0; i<n; i++) {
                if(dist[i] <= distanceThreshold) count++;
            }
            p_answers[src] = count;
            src++;
        }

        int min = INT_MAX;
        int ans = -1;
        for(int i=0; i<n; i++) {
            if(p_answers[i] <= min) {
                min = p_answers[i];
                ans = i;
            }
        }

        return ans;
    }
};
