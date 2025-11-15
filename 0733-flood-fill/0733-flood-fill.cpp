class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(vector<vector<int>>& image , int sr,int sc,int color,int original){
        queue<pair<int,int>>que;
        que.push({sr,sc});
        image[sr][sc]=color;
        int n = image.size();
        int m = image[0].size();
        auto issafe = [&](int x,int y){
             return (x >= 0 && x < n && y >= 0 && y < m);
        };
        
        while(!que.empty()){
            auto top = que.front();
            que.pop();
            int r = top.first;
            int c = top.second;
            for(auto &dir : directions){
                int new_r = dir[0]+r;
                int new_c = dir[1]+c;
                if(issafe(new_r,new_c) && image[new_r][new_c]==original){
                    image[new_r][new_c]=color;
                    que.push({new_r,new_c});
                }
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int original = image[sr][sc];
          if(original==color){
            return image;
          }
          bfs(image,sr,sc,color,original);

          return image;
    }
};