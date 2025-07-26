from typing import List

class Solution:
    def dfs(self, node: int, visited: List[bool], stack: List[int], adj: List[List[int]]):
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, stack, adj)
        stack.append(node)

    def topoSort(self, V: int, adj: List[List[int]]) -> List[int]:
        visited = [False] * V
        stack = []

        for i in range(V):
            if not visited[i]:
                self.dfs(i, visited, stack, adj)

        return stack[::-1]  # Reverse to get correct topological order

# Driver Code
if __name__ == "__main__":
    adj = [[], [], [3], [1], [0, 1], [0, 2]]
    V = 6
    obj = Solution()
    ans = obj.topoSort(V, adj)
    print("Topological Sort:", *ans)
