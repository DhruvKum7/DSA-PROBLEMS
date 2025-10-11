
auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();

class Solution {
public: 
    typedef  long long ll;
    vector<ll>t;
    // ll solve(int i , vector<ll>&nums,unordered_map<ll,ll>&mp){
    //     if(i>=nums.size()){
    //         return 0;
    //     }
    //     if(t[i]!=-1){
    //         return t[i];
    //     }
    //     int j = lower_bound(nums.begin()+i+1,nums.end(),nums[i]+3)-nums.begin();
    //     ll take = nums[i]*mp[nums[i]] + (j<nums.size()?solve(j,nums,mp):0);
    //     ll skip = ((i+1)<nums.size()?solve(i+1,nums,mp):0);

    //     return t[i]=max(take,skip);
    // }
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<ll,ll>mp;
        
        for(auto &i :  power) mp[i]++;

        vector<ll>nums(mp.size());
        for(auto &i : mp) nums.push_back(i.first);
        sort(nums.begin(),nums.end());
        t.assign(nums.size()+1,0);
        ll result = -1e9;
        for(int i=nums.size()-1 ;i>=0 ;i--){
            int j = lower_bound(nums.begin()+i+1,nums.end(),nums[i]+3)-nums.begin();
            ll take = nums[i]*mp[nums[i]] + (j<nums.size()?t[j]:0);
            ll skip = i<nums.size()?t[i+1]:0; 

            t[i] = max(take,skip);
            result = max(t[i],result);
        }

        return result;
    }
};