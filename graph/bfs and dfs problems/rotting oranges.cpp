class Solution {
public:
    // Define alias for coordinate pair
    typedef pair<int, int> p;

    // Directions for Up, Down, Left, Right movement
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();         // Number of rows
        int m = grid[0].size();      // Number of columns
        int fresh = 0;               // Count of fresh oranges
        int time = 0;                // Time counter for BFS levels (minutes)

        queue<p> q;  // Queue for BFS (holds rotten orange positions)

        // ✅ STEP 1: Count fresh oranges & enqueue all rotten ones (multi-source BFS setup)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});  // Enqueue all initially rotten oranges
                } else if (grid[i][j] == 1) {
                    fresh++;         // Count fresh oranges
                }
            }
        }

        // If no fresh orange exists from the beginning
        if (fresh == 0) return 0;

        // ✅ STEP 2: Lambda function to check if a cell is valid and contains a fresh orange
        auto issafe = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1;
        };

        // ✅ STEP 3: BFS traversal (multi-source, level-by-level)
        while (!q.empty()) {
            int size = q.size();  // Number of rotten oranges at current time step

            while (size--) {
                p curr = q.front(); q.pop();
                int index_i = curr.first;
                int index_j = curr.second;

                // Check 4-directionally adjacent cells
                for (auto& dir : directions) {
                    int new_i = index_i + dir[0];
                    int new_j = index_j + dir[1];

                    // If neighbor is a fresh orange
                    if (issafe(new_i, new_j)) {
                        grid[new_i][new_j] = 2;    // Rot the fresh orange
                        q.push({new_i, new_j});    // Add to queue to rot its neighbors later
                        fresh--;                   // One less fresh orange
                    }
                }
            }

            // After processing one BFS level, increment time
            time++;
        }

        // ✅ STEP 4: Check if all fresh oranges are rotten
        return (fresh == 0) ? time - 1 : -1;
        // (Subtract 1 because last level increments time even if no fresh oranges were rotted)
    }
};
