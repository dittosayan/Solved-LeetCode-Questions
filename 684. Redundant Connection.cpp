class Solution {
public:
    int find(vector<int>& parent, int k){
        if(parent[k]==k)
            return k;
        return parent[k]=find(parent,parent[k]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> parent(n+1,-1);
        
        for(int i=1;i<=n;i++)
            parent[i]=i;
        
        for(int i=0;i<n;i++){
            int p0=find(parent,a[i][0]);
            int p1=find(parent,a[i][1]);
            
            if(p0==p1)
                return a[i];
            parent[p1]=p0;
        }
        
        return {-1,-1};
    }
};
