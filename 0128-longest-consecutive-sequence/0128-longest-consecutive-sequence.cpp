class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;   // FIX: handle empty input

        unordered_set<int> st;
        for(auto &i : nums){
            st.insert(i);
        }

        int longest = 1;

        for(auto &i : st){

            // FIX: only start counting if it's the start of a sequence
            if(st.find(i - 1) != st.end()) continue;

            int x = i;
            int cnt = 1;   // FIX: start from 1

            while(st.find(x + 1) != st.end()){
                x = x + 1;
                cnt++;
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};
