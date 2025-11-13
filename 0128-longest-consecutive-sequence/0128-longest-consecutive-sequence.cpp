class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;   // FIX: handle empty input

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;
        int last_no = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] == last_no) 
                continue;     // FIX: skip duplicates

            if(nums[i] - 1 == last_no) {
                cnt++;
            } 
            else {
                cnt = 1;
            }

            last_no = nums[i];
            longest = max(longest, cnt);
        }

        return longest;
    }
};
