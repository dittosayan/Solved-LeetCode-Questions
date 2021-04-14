class Solution {
public:
    void dfs(string& a,vector<string>& curr, vector<vector<string>>& res,
             vector<vector<bool>>& dp, int start){
        
        if(start>=a.length()){
            res.push_back(curr);
            return;
        }
        
        for(int end=start;end<a.length();end++){
            if(a[end]==a[start] && ((end-start)<=2 || dp[start+1][end-1])){
                dp[start][end]=true;
                curr.push_back(a.substr(start,end-start+1));
                dfs(a,curr,res,dp,end+1);
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        if(n==0)
            return {};
        if(n==1)
            return {{s}};
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        vector<string> curr;
        vector<vector<string>> res;
        
        dfs(s,curr,res,dp,0);
        
        return res;
    }
};
