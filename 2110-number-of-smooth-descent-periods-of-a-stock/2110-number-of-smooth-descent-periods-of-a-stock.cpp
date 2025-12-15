class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 1, result = 1;
        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) count++;
            else count = 1;
            result += count;
        }
        return result;
    }
};