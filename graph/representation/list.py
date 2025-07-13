def main():
    # Read number of nodes (n) and edges (m) from input and map converts string to integer
    n, m = map(int, input().split())

    # Initialize adjacency list: a list of empty lists for each node (1-based indexing)
    graph = [[] for _ in range(n + 1)]

    # Read edges and build the adjacency list
    for _ in range(m):
        u, v = map(int, input().split())  # Read an edge between nodes u and v
        graph[u].append(v)  # Add v to the neighbors of u
        graph[v].append(u)  # Add u to the neighbors of v (undirected graph)

    # Print adjacency list for each node
    for i in range(1, n + 1):
        for neighbor in graph[i]:
            print(neighbor, end=" ")  # Print neighbors in one line separated by space
        print()  # New line after each node’s neighbors

if __name__ == "__main__":
    main()
