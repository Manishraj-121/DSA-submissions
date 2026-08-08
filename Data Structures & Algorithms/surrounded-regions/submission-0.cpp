class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // store O's coordinate in queue that is present at boundary
        // then solve by multisounces bfs
        
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' &&(i==0 || i==n-1 || j==0 || j==m-1)){
                   q.push({i,j});
                   visited[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                   board[i][j]='X';
                }
            }
        }
    }
};
