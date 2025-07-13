from collections import deque

def bfs_of_graph(V, adj):
    visited = [False] * V
    bfs_result = []
    q = deque()

    visited[0] = True  # Starting from node 0
    q.append(0)

    while q:
        node = q.popleft()
        bfs_result.append(node)

        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                q.append(neighbor)

    return bfs_result

# Taking user input
V = int(input("Enter number of vertices (V): "))
E = int(input("Enter number of edges (E): "))

adj = [[] for _ in range(V)]

print("Enter edges (u v):")
for _ in range(E):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)  # Remove this line if the graph is directed

# Call BFS
result = bfs_of_graph(V, adj)

# Output
print("BFS Traversal starting from node 0:")
print(*result)
