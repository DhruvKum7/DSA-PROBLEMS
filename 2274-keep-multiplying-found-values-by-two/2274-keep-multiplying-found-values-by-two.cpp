class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto &i : nums){
            st.insert(i);
        }
        
        int ans = original;
        while(st.count(ans)){
          ans = 2*ans;

        }
        return ans;
    }
};