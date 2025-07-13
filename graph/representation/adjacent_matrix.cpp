#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // This is our adjacency matrix
    // All the elements are initialized to zero
    vector < vector < int >> adjMatrix(n + 1, vector < int > (n + 1, 0));

    // Take the input for all the edges
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;

        // Adding an edge from u to v
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1;
    }

    // Printing the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}