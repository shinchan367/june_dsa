#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
   cin >> n >> m;
    vector<int> graph[n + 1]; // 1-based node indexing
    // There are no elements currently in any list
    // Below is our input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout<<"\n";
    }
    return 0;
}