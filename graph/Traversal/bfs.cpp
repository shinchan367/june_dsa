#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<bool> visited(V, false);
    queue<int> q;

    visited[0] = true;  // Assuming BFS starts from node 0
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return bfs;
}

int main() {
    int V, E;
    cout << "Enter number of vertices (V): ";
    cin >> V;

    cout << "Enter number of edges (E): ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line if the graph is directed
    }

    vector<int> result = bfsOfGraph(V, adj);

    cout << "BFS Traversal starting from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
