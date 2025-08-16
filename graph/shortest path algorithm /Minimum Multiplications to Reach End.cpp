class Solution{
public:
    int minimumMultiplications(vector<int> &arr,int start, int end) {
   int mod=100000;
   if(start==end)return 0;
   queue<pair<int,int>>q;
   vector<int>dist(100000,1e9);
   dist[start]=0;
   q.push({start,0});
   while(!q.empty()){
    int start_=q.front().first;
    int distance=q.front().second;
    q.pop();
    for(auto it:arr){
        int num=(it*start_)%mod;
        if(distance+1<dist[num]){
            dist[num]=distance+1;
            if(num==end){
                return distance+1;
            }
            q.push({num,distance+1});
        }
        
    }
   }
   return -1;
    }
};
