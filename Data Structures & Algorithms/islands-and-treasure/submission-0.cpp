class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //take queue where we store the cordinate of treasure
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>distance=grid;

        // traverse grid and store cordi of 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int dist=q.front().first;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] !=-1){
                   
                    if(distance[nrow][ncol]>dist+1){
                       distance[nrow][ncol]=dist+1;
                       q.push({dist+1,{nrow,ncol}});
                    }
                }
            }
        }
        grid=distance;
    }
};
