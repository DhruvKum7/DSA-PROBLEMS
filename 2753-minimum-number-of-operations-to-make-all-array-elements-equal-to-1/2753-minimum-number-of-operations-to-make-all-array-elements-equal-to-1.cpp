class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long count = 0;
        int operations = INT_MAX;
        int n = nums.size();

        // Count how many 1s are already present
        for (auto &i : nums) {
            if (i == 1) {
                count++;
            }
        }

        // Case 1: If there are already 1s present
        if (count > 0) {
            return n - count;
        }

        // Case 2: Try to find the smallest subarray with gcd = 1
        for (int i = 0; i < n; i++) {
            int gcd__ = nums[i];
            for (int j = i + 1; j < n; j++) {
                gcd__ = std::gcd(gcd__, nums[j]); // ✅ update gcd cumulatively
                if (gcd__ == 1) {
                    operations = min(operations, j - i);
                   // break; // no need to continue once gcd becomes 1
                }
            }
        }

        // If we never find a subarray with gcd 1, it's impossible
        if (operations == INT_MAX) {
            return -1;
        }

        // Otherwise, total operations = (operations to make one 1) + (make all others 1)
        return operations + n - 1;
    }
};
