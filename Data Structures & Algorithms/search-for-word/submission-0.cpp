class Solution {
private:
    bool f(int row, int col, string word, string s, vector<vector<char>>& board, int k){
        int n=board.size();
        int m=board[0].size();
        if(k==word.size())return true;
        if (row < 0 || row >= n || col < 0 || col >= m)
            return false;

        if (board[row][col] != word[k])
            return false;

        char ch = board[row][col];
        board[row][col] = '#';

        if (f(row + 1, col, word, s + word[k], board, k + 1))
            return true;

        if (f(row, col + 1, word, s + word[k], board, k + 1))
            return true;

        if (f(row, col - 1, word, s + word[k], board, k + 1))
            return true;

        if (f(row - 1, col, word, s + word[k], board, k + 1))
            return true;

        board[row][col] = ch;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int k=0;
        string s="";

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[k]){
                    if(f(i, j,word,s, board, k)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// class Solution {
// private:
//     bool f(int row, int col, vector<vector<char>>& board, string word, int delrow[], int delcol[], int k){
//         if()
//         int n=board.size();
//         int m=board[0].size();
//         for(int l=0; l<4; l++){
//             int nrow=row+delrow[l];
//             int ncol=col+delcol[l];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[k]){
//                 k++;
//             }
//             if(k==word.size())return true;
//         }
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int n=board.size();
//         int m=board[0].size();
//         int k=0;
//         int delrow[]={-1,0,1,0};
//         int delcol[]={0,1,0,-1};

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(board[i][j]==word[k]){
//                     f(i, j, board, word, delrow, delcol, k);
//                 }
//             }
//         }
//         return false;
//     }
// };
