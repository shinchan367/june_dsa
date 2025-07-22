class Solution {
public:
int n,m;
vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1){
        return;
    }
    grid[i][j]=0;

    for(auto dir:directions){
        int newi=dir[0]+i;
        int newj=dir[1]+j;
        dfs(grid,newi,newj);
    }
    
   }


    int sum=0;
    int numEnclaves(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)dfs(grid,0,i);
            if(grid[n-1][i]==1)dfs(grid,n-1,i);
        }
        for(int j=0;j<n;j++){
            if(grid[j][0]==1)dfs(grid,j,0);
            if(grid[j][m-1]==1)dfs(grid,j,m-1);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                  sum+=1;
                }
            }

        }
        return sum;
    }
};
