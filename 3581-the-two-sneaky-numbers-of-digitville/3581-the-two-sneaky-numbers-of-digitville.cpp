class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2; // array has n+2 elements with 2 repeating numbers
        int xorr = 0;

        // XOR all elements in nums
        for (auto &i : nums) {
            xorr ^= i;
        }

        // XOR with numbers from 0 to n
        for (int i = 0; i <= n-1; i++) {
            xorr ^= i;
        }

        // Find rightmost set bit (difference bit)
        int countbit = __builtin_ctz(xorr);
        int separator = 1 << countbit;

        int g1 = 0, g2 = 0;

        // Divide nums into two groups and XOR separately
        for (auto &i : nums) {
            if (i & separator)
                g1 ^= i;
            else
                g2 ^= i;
        }

        // Divide 0..n into same two groups and XOR
        for (int i = 0; i <= n-1; i++) {
            if (i & separator)
                g1 ^= i;
            else
                g2 ^= i;
        }

        return {g1, g2};
    }
};
