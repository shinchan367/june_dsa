def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])

    # Initialize the adjacency matrix with zeroes
    adjMatrix = [[0] * (n + 1) for _ in range(n + 1)]

    # Read the edges and update the adjacency matrix
    index = 2
    for _ in range(m):
        u = int(data[index])
        v = int(data[index + 1])
        index += 2

        # Adding an edge from u to v
        adjMatrix[u][v] = 1
        adjMatrix[v][u] = 1

    # Print the adjacency matrix
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(adjMatrix[i][j], end=" ")
        print()

if __name__ == "__main__":
    main()
