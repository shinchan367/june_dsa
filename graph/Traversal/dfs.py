from typing import List

class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[int], res: List[int]):
        visited[node] = 1
        res.append(node)
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited, res)

    def dfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [0] * V
        res = []
        self.dfs(0, adj, visited, res)  # Start DFS from node 0
        return res

# Function to add undirected edge
def addEdge(adj: List[List[int]], u: int, v: int):
    adj[u].append(v)
    adj[v].append(u)

# Function to print DFS result
def printAns(ans: List[int]):
    for node in ans:
        print(node, end=' ')
    print()

# Main
if __name__ == "__main__":
    V = int(input("Enter number of vertices (V): "))
    E = int(input("Enter number of edges (E): "))

    adj = [[] for _ in range(V)]

    print("Enter edges (u v):")
    for _ in range(E):
        u, v = map(int, input().split())
        addEdge(adj, u, v)

    obj = Solution()
    ans = obj.dfsOfGraph(V, adj)
    print("DFS Traversal starting from node 0:")
    printAns(ans)
