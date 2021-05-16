class Solution {
public:
    unordered_map<string,bool> dp;
    bool dfs(int start, string& a, unordered_set<string>& m, bool parted) {
        
        string substr=a.substr(start);
        if(dp.count(substr)>0)
            return dp[substr];
        
        string add="";
        for(int i=start;i<a.size();i++){
            
            add+=a[i];
            
            if(m.count(add)>0){
                
                if(i==a.size()-1)
                    return parted;
                
                if(dfs(i+1,a,m,true))
                    return dp[substr]=true;
            }
        }
        
        return dp[substr]=false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> m;
        for(auto word:words)
            m.insert(word);
        
        vector<string> res;
        for(auto word:words){
            if(dfs(0,word,m,false))
                res.push_back(word);
        }
        
        return res;
    }
};
