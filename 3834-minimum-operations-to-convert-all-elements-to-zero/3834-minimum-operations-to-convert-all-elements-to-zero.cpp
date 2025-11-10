class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long ops = 0;
        stack<int>st;
        for(auto &i : nums){
            while(!st.empty() && st.top()>i){
                //ops++;
                st.pop();
            }
            if(i==0){
                continue;
            }
            if(st.empty() || st.top()<i){
            st.push(i);
            ops++;
            }
        }
        return ops;
    }
};