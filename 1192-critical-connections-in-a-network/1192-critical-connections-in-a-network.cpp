class Solution {
public:
    void dfs(int node,vector<int>&dis,vector<int>&low,unordered_map<int,vector<int>>&mp,vector<int>&parent,vector<bool>&vis,vector<vector<int>>&result,int &timer){
        vis[node]=true;
        dis[node]=low[node]=timer++;
        for(auto &e : mp[node]){
            if(e==parent[node]){
                continue;
            }
            if(!vis[e]){
                parent[e]=node;
                dfs(e,dis,low,mp,parent,vis,result,timer);
                low[node]=min(low[node],low[e]);
                if(dis[node]<low[e]){
                    result.push_back({node,e});
                }

                
            }
            else{
                low[node]=min(low[node],dis[e]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>mp;
        for(auto &v : connections){
            int fir = v[0];
            int sec = v[1];

            mp[fir].push_back(sec);
            mp[sec].push_back(fir);
        }
        int timer = 0;
        vector<int>dis(n,-1);
        vector<bool>vis(n,false);
        vector<int>low(n,-1);
        vector<int>parent(n,-1);
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(i,dis,low,mp,parent,vis,result,timer);
            }
        }
        return result;
    }
};