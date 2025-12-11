class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>>rows,cols;
        for(auto &i : buildings){
            int u = i[0];
            int v = i[1];

            rows[u].push_back(v);
            cols[v].push_back(u);

        }
        for(auto &i : cols){
            auto &v = i.second;
            sort(v.begin(),v.end());
        }
        for(auto &i : rows){
            auto &v = i.second;
            sort(v.begin(),v.end());
        }
        long long count = 0;
        for(auto &i : buildings){
            int x = i[0];
            int y = i[1];

            auto &xx = rows[x];
            auto &xy = cols[y];

            if(xy.front()<x && xy.back()>x && xx.front()<y && xx.back()>y){
                count++;
            }
        }
        return count;
    }
};