#define pii pair<int,int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pii> a[n+1];
        for(auto edge:times)
            a[edge[0]].push_back({edge[1],edge[2]});
        
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        
        // priority queue ordered by first
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            
            int u=pq.top().second;
            pq.pop();
            
            for(auto &nodes:a[u]){
                
                int v=nodes.first;
                int w=nodes.second;
                
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int res=*max_element(dist.begin()+1,dist.end());
        return res==INT_MAX?-1:res;
    }
};
