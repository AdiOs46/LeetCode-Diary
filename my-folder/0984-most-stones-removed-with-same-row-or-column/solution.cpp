class Solution {
public:
    int findPar(int node, vector<int>& parent) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node], parent);
    }

    void makeUnion(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findPar(u, parent);
        int pv = findPar(v, parent);

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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    makeUnion(i, j, parent, rank);
            }
        }
            
        
        set<int> components;
        for(int i=0; i<n; i++)
            components.insert(findPar(i, parent));

        return n - components.size();


    }
};
