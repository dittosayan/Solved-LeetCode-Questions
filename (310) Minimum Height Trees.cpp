// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base case
        if(n==1)
            return {0};
        if(n==2)
            return {0,1};
        
        // Build adjacency list
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Initialialize queue with leaves
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1)
                q.push(i);
        }
        
        // Reprocess queue until you have one or two nodes left
        int rem=n;
        while(rem>2){
            rem=rem-q.size();
            int k=q.size();
            while(k--){
                int leaf=q.front();
                q.pop();
                
                // find the only neighbor of the leaf and delete that from
                // the neighbors adjacency array
                int nghbr=adj[leaf][0];
                auto position=find(adj[nghbr].begin(),adj[nghbr].end(),leaf);
                if(position!=adj[nghbr].end())
                    adj[nghbr].erase(position);
                
                // If the neighbor becomes a new leaf add to the queue
                if(adj[nghbr].size()==1)
                    q.push(nghbr);
            }
        }
        
        // anything remaining in the queue is a centroid and thus the answer
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
