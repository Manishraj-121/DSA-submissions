class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<int> ind(numCourses,0);
        vector<int> topo;
        for(int i=0; i<numCourses; i++){
            for(auto it : adj[i]){
               ind[it]++;
            }
        }
        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        return (topo.size()==numCourses);
    }
};
