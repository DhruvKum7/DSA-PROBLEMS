class Solution {
public:
    void dfs( unordered_map<int,vector<int>>&adj,vector<int>&disc, vector<int>&low, vector<bool>&vis, vector<int>&parent,int node, vector<vector<int>>&result,int &timer){
            vis[node]=true;
            disc[node]=low[node]=timer++;

            for(auto &ngbr : adj[node]){
                if(ngbr==parent[node]){
                    continue;
                }
                if(!vis[ngbr]){
                    parent[ngbr]=node;
                    dfs(adj,disc,low,vis,parent,ngbr,result,timer);
                    low[node]=min(low[node],low[ngbr]);

                    if(disc[node]<low[ngbr]){
                        vector<int>ans;
                        ans.push_back(node);
                        ans.push_back(ngbr);

                        result.push_back(ans);
                    }
                }else{
                    low[node]=min(low[node],disc[ngbr]);
                }
            }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       unordered_map<int,vector<int>>adj;
       for(auto &e : connections){
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       } 
       int timer = 0;
       vector<int>disc(n,-1);
       vector<int>low(n,-1);
       vector<bool>vis(n,false);
       vector<int>parent(n,-1);


       vector<vector<int>>result;

       for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,disc,low,vis,parent,i,result,timer);
        }
       }
       return result;
    }
};