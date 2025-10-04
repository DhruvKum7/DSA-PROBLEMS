class Solution {
public:
    int maxArea(vector<int>& height) {
        long long ans = 0;
        int i = 0, j = (int)height.size() - 1;
        while (i < j) {
            long long h = min(height[i], height[j]);
            long long w = j - i;
            ans = max(ans, h * w);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return (int)ans;
    }
};
