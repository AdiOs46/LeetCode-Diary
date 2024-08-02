class Solution {
private:
    int findPar(vector<int>& par, int node) {
        if(par[node] == node) return node;
        return par[node] = findPar(par, par[node]);
    }

    void makeUnion(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findPar(parent, u);
        int pv = findPar(parent, v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) 
            parent[pu] = pv;
        else if(rank[pu] > rank[pv])  
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<int> parent(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;

        vector<int> rank(n);

        for(auto it : connections) {
            int u = it[0];
            int v = it[1];
            makeUnion(u, v, parent, rank);
        }

        set<int> groups;
        for(int i=0; i<n; i++) {
            int par = findPar(parent, i);
            groups.insert(par);
        }
        int unions = groups.size();
        return unions-1;
    }
};
