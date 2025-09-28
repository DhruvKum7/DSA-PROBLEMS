#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) return 0;

       
        for (int j = n - 1; j >= 2; --j) {
            if (nums[j - 2] + nums[j - 1] > nums[j]) {
                return nums[j - 2] + nums[j - 1] + nums[j];
            }
        }
        return 0;
    }
};
