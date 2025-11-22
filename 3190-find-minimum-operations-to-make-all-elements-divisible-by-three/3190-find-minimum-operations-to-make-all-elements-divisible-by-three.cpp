class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto lambda = [](int x) {
            return x % 3 != 0;
        };
        return count_if(nums.begin(), nums.end(), lambda);
    }
};
