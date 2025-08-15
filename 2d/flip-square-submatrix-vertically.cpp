class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
    int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> grids = grid;

      
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                grids[x + i][y + j] = grid[x + (k - 1 - i)][y + j];
            }
        }
        return grids;
    }
};
