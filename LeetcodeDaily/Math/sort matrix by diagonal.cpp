class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mpp;
        int n = grid.size();

        for(int i = 0; i < n ;i++){
            for(int j = 0 ;j < n;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it : mpp){
            if(it.first < 0){
                sort(begin(it.second),end(it.second));
            }
            else{
                sort(begin(it.second),end(it.second),greater<int>());
            }
        }

        for(int i = n-1;i >=0;i--){
            for(int j = n-1;j >=0 ;j--){
                grid[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
        }

        return grid;
    }
};


//////////////////////////////
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>>mp;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
            if(it.first>=0){
                sort(it.second.begin(), it.second.end(), greater<int>());
            }
        }
       
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};
