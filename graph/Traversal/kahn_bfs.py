from typing import List
from collections import deque

class Solution:
    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        indegree = [0] * V

        # Step 1: Compute indegrees
        for i in range(V):
            for node in adj[i]:
                indegree[node] += 1

        # Step 2: Push nodes with 0 indegree into the queue
        q = deque()
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        # Step 3: Kahn's Algorithm - BFS
        topo = []
        while q:
            node = q.popleft()
            topo.append(node)

            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return topo

# Driver Code
if __name__ == "__main__":
    adj = [[], [], [3], [1], [0, 1], [0, 2]]
    V = 6
    obj = Solution()
    ans = obj.topoSort(V, adj)
    print("Topological Sort:", *ans)
