class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = LLONG_MIN;

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int start = 0; start < k; start++) {
            int i = start;
            long long curr = LLONG_MIN;

            while (i < n && i + k - 1 < n) {
                int j = i + k - 1;

                long long subarr = prefix[j] - (i > 0 ? prefix[i - 1] : 0);

                curr = (curr == LLONG_MIN) ? subarr : max(subarr, curr + subarr);

                result = max(result, curr);

                i += k;
            }
        }
        return result;
    }
};
