class Solution {
    public:
      void topo(vector<int>&vis,int i,vector<pair<int,int>>adj[],stack<int>&st,int N){
        vis[i]=1;
       for (auto it : adj[i]) {
               int v = it.first;
               if (!vis[v]) {
                    topo(vis, v,adj, st, N);
               }
          }
          st.push(i);
     }

    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
    vector<pair<int,int>>adj[N];
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        adj[u].push_back({v,wt});
    }
   vector<int> vis(N, 0);
    stack<int>st;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            topo(vis,i,adj,st,N);
        }
    }
    vector<int> dist(N);
    for(int i=0;i<N;i++){
        dist[i]=1e9;
    }

    dist[0]=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
         
         for(auto it:adj[top]){
            int v=it.first;
            int wt=it.second;
            if(dist[top]+wt<dist[v]){
                dist[v]=dist[top]+wt;
            }
         }
    }
         for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;

    

    }
};

