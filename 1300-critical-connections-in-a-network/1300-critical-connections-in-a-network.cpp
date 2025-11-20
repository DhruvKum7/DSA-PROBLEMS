class Solution {
public:
    void dfs( unordered_map<int,vector<int>>&adj,int &timer,vector<int>&low, vector<bool>&vis,vector<int>&parent,vector<int>&disc,vector<vector<int>>&result,int i){
        vis[i]=true;
        disc[i]=low[i]=timer++;
      //  parent[i]=low[i-1];
        for(auto &ngbr : adj[i]){
            if(ngbr==parent[i]){
                continue;
            }
            if(vis[ngbr]==false){
                parent[ngbr]=i;
                dfs(adj,timer,low,vis,parent,disc,result,ngbr);
                low[i]=min(low[i],low[ngbr]);
                if(low[ngbr]>disc[i]){
                    vector<int>ans;
                    ans.push_back(i);
                    ans.push_back(ngbr);

                    result.push_back(ans);
                }
            }
            else{
                low[i]=min(low[i],low[ngbr]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>adj;
       // int v = n;
        for(auto &i : connections){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        vector<bool>vis(n,false);
        vector<int>parent(n,-1);
        parent[0]=-1;
        vector<vector<int>>result; 
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj,timer,low,vis,parent,disc,result,i);
            }
        }
        return result;
    }
};