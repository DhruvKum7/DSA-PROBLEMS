class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0;
        for (auto &i : nums) {
            total += i;
        }
        long long sum = 0;
        int result = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            long long ans = 2LL * sum - total;
            if (ans % 2 == 0) {
                result++;
            }
        }
        return result;
    }
};
