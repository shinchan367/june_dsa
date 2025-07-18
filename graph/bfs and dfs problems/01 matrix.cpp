
class Solution {
public:

typedef pair<int,int>p;
vector<vector<int>>directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>newmat(n,vector<int>(m,-1));
        queue<p>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                 q.push({i,j});
                 newmat[i][j]=0;
                }
            }
        }
        auto issafe=[&](int &new_i,int &new_j){
              return new_i>=0 && new_i<n && new_j>=0 && new_j<m;
        };
        while(!q.empty()){
            p curr=q.front();
            q.pop();
            for(auto it:directions){
            int new_i=curr.first+it[0];
            int new_j=curr.second+it[1];
            if(issafe(new_i,new_j)){
               if(newmat[new_i][new_j]== -1){
                q.push({new_i,new_j});
                newmat[new_i][new_j]=1+newmat[curr.first][curr.second];
               }
            }
             
            
        }
          
    }
     return newmat;     
    }
};
