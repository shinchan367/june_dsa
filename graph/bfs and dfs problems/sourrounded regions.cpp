class Solution {
public:
int n,m;
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>&board,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O'){
            return;
        }
        board[i][j]='#';

        for(auto dir:directions){
            int ni=dir[0]+i;
            int nj=dir[1]+j;
            dfs(board,ni,nj);
        }

    }



    void solve(vector<vector<char>>& board) {
        if(board.size()==0)return;
         n=board.size();
     m=board[0].size();

        for(int i=0;i<m;i++){
            if(board[0][i]=='O')dfs(board,0,i);
            if(board[n-1][i]=='O')dfs(board,n-1,i);
            
        }
        for(int j=0;j<n;j++){
            if(board[j][0]=='O')dfs(board,j,0);
            if(board[j][m-1]=='O')dfs(board,j,m-1);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }

    }
};
