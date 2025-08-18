#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to implement 
    Bellman Ford Algorithm */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, 
                             int S) {
                                 
        // To store the distance
        vector<int> dist(V, 1e9);
        
        // Distane of source from itself is zero
        dist[S] = 0;
        
        // Repeat for V-1 times
        for(int i=0; i<V-1; i++) {
            
            // Iterate on all the edges
            for(auto it : edges) {
                
                int u = it[0]; // node 1
                int v = it[1]; // node 2
                int wt = it[2]; // edge weight
                
                // Edge relaxation
                if(dist[u] != 1e9 && 
                   dist[u] + wt < dist[v]) {
                       
                    // Updating the known distance
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        /* An extra relaxation to check if the 
        graph consists of a negative cycle */
        for(auto it : edges) {
            
            int u = it[0]; // node 1
            int v = it[1]; // node 2
            int wt = it[2]; // edge weight
            
            /* If edge relaxation is possible, 
            negative cycle exists */
            if(dist[u] != 1e9 && 
               dist[u] + wt < dist[v]) {
                   
                // Return {-1}
                return {-1};
            }
        }
        
        // Return the computed result
        return dist;
    }
};

int main() {
    int V = 6, S = 0;
    vector<vector<int>> edges = {
        {3, 2, 6}, {5, 3, 1}, 
        {0, 1, 5}, {1, 5, -3}, 
        {1, 2, -2}, {3, 4, -2}, 
        {2, 4, 3}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to implement 
    Bellman Ford Algorithm */
    vector<int> ans = sol.bellman_ford(V, edges, S);
    
    // Output
    if(ans == vector<int>(1, -1))
        cout << "The graph contains negative cycle.";
    else{
        cout << "The shortest distance from source is: ";
        for(int i=0; i < V; i++) {
            cout << ans[i] << " ";
        }
    }
    
    return 0;
}



class Solution:

    # Function to implement 
    # Bellman Ford Algorithm
    def bellman_ford(self, V, edges, S):
        
        # To store the distance
        dist = [int(1e9)] * V
        
        # Distance of source from itself is zero
        dist[S] = 0
        
        # Repeat for V-1 times
        for _ in range(V-1):
            
            # Iterate on all the edges
            for u, v, wt in edges:
                
                # Edge relaxation
                if (dist[u] != int(1e9) and 
                    dist[u] + wt < dist[v]):
                       
                    # Updating the known distance
                    dist[v] = dist[u] + wt
        
        # An extra relaxation to check if the 
        # graph consists of a negative cycle
        for u, v, wt in edges:
            
            # If edge relaxation is possible, 
            # negative cycle exists
            if (dist[u] != int(1e9) and 
                dist[u] + wt < dist[v]):
                   
                # Return [-1]
                return [-1]
        
        # Return the computed result
        return dist


if __name__ == "__main__":
    V, S = 6, 0
    edges = [
        [3, 2, 6], [5, 3, 1], 
        [0, 1, 5], [1, 5, -3], 
        [1, 2, -2], [3, 4, -2], 
        [2, 4, 3]
    ]
    
    # Creating an instance of 
    # Solution class
    sol = Solution()
    
    # Function call to implement 
    # Bellman Ford Algorithm
    ans = sol.bellman_ford(V, edges, S)
    
    # Output
    if ans == [-1]:
        print("The graph contains negative cycle.")
    else:
        print("The shortest distance from source is: ", end=" ")
        for d in ans:
            print(d, end=" ")
