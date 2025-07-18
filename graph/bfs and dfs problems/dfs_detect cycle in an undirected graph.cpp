class Solution {
public:
    bool detect(int node, int parent, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (detect(neighbor, node, adj, visited))
                    return true;
            }
            else if (neighbor != parent) {
                // Cycle detected
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (detect(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};
////////////////
class Solution:
    def detect(self, node, parent, adj, visited):
        visited[node] = True
        
        for neighbor in adj[node]:
            if not visited[neighbor]:
                if self.detect(neighbor, node, adj, visited):
                    return True
            elif neighbor != parent:
                # Found a back edge, so cycle exists
                return True
                
        return False

    def isCycle(self, V, adj):
        visited = [False] * V
        for i in range(V):
            if not visited[i]:
                if self.detect(i, -1, adj, visited):
                    return True
        return False
