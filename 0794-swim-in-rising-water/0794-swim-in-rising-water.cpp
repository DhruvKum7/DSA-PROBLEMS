class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    using p = pair<int,pair<int,int>>;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>result(n,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        result[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int current = pq.top().first;
            auto dir = pq.top().second;
            int fir = dir.first;
            int sec = dir.second;
            pq.pop();

            if(fir==n-1 && sec==n-1){
                return current;
            }
            if(current > result[fir][sec]){
                continue;
            }
            for(auto &dis : directions){
                int i_=dis[0]+fir;
                int j_=dis[1]+sec;

                if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n){
                    int next = max(current,grid[i_][j_]);
                    if(next<result[i_][j_]){
                        result[i_][j_]=next;
                        pq.push({result[i_][j_],{i_,j_}});
                    }
                }
            }
        }
        return -1;
    }
};