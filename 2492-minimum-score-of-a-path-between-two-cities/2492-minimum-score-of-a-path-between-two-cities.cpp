class Solution {
public:
    void dfs(int node,unordered_map<int,vector<pair<int,int>>>&mp,vector<vector<int>>& roads,int n,int &ans,vector<bool>&vis){
        vis[node]=true;
        for(auto &ed : mp[node]){
            int v = ed.first;
            int u = ed.second;
            ans = min(ans,u);
            if(vis[v]==false){
                dfs(v,mp,roads,n,ans,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto &ed : roads){
            int u = ed[0];
            int v = ed[1];
            int w = ed[2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        vector<bool>vis(n+1,false);
        int ans = INT_MAX;
       
                dfs(1,mp,roads,n,ans,vis);
            
       
        return ans;
    }
};