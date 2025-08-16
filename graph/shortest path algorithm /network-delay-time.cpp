class Solution {
public:
#define p pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<vector<p>>adj(n+1);
        for(auto it:times){
           adj[it[0]].push_back({it[2],it[1]});
        }
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int start=pq.top().first;
            int weight=pq.top().second;
            pq.pop();
            if(start > dist[weight]) continue;

            for(auto it:adj[weight]){
                int wei=it.first; 
                int nextnode=it.second;
                if(wei+start<dist[nextnode]){
                    dist[nextnode]=wei+start;
                    pq.push({dist[nextnode],nextnode});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
                maxi=max(maxi,dist[i]);
            
        }
        return maxi;
    }
};
