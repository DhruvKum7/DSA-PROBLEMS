class Solution {
public:
    const int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto &i : points){
            int u = i[1];
            mp[u]++;
        }
        long long total = 0;
        long long ans = 0;
        for(auto &i : mp){
            long long u = i.second;
            long long horizontal = (u*(u-1))/2;
            total+=horizontal*ans;
            ans+=horizontal;
        }

        return total % M;
    }
};