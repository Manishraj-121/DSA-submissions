class Solution {
private: 
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node]=1;

        for(auto it : adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                dfs(it,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
       // first of all find adjacency list
       // take a array of size n, start traversing from zero
       // and use dfs on that node 
       // take a visited array (mark it when you visite)
       // increase count value on dfs
       // return count 
       // it little bit similar to no. of Islands

       vector<vector<int>> adj(n);

       // now find adjlist
       for(int i=0; i<edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       int count=0;

       // take a visited array
       vector<int> vis(n,0);
       
       // traverse from 0 to n-1 , so that every node must be visit
       for(int i=0; i<n; i++){
           if(vis[i]==0){
            count++;
            dfs(i,adj,vis);
           }
       }
       return count;
    }
};
