from collections import deque
class Solution:
    def detect(self,i,adj,visited):
        q=deque()
        visited[i]=True
        q.append((i,-1))
        while q:
            source,parent=q.popleft()
            for neighbor in adj[source]:
                if not visited[neighbor]:
                    visited[neighbor]=True
                    q.append((neighbor,source))
                elif neighbor != parent:
                    return True

        return False




    def isCycle(self, V, adj):
        visited=[False]*V
        for i in range(V):
            if not visited[i] and self.detect(i,adj,visited):
                return True
        return False 

  //////////////////////////////////////////////////////////
  class Solution{
public:
    typedef pair<int,int>p;
   bool detect(vector<int>adj[],vector<bool>&visited,int i){
        queue<p>q;
        visited[i]=true;
        q.push({i,-1});
        while(!q.empty()){
            p curr=q.front();
            q.pop();
            int source=curr.first;
            int parent=curr.second;
            for(auto &it:adj[source]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,source});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
       return false;
   }
   
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && detect(adj,visited,i)){
                return true;
            }
        }
        return false;
            }
};
