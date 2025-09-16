class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        for (long long x : nums) {
            while (!st.empty()) {
                long long g = std::gcd(st.back(), x);
                if (g == 1) break;
                x = (st.back() / g) * x;
                st.pop_back();
            }
            st.push_back(x);
        }
        vector<int> res;
        res.reserve(st.size());
        for (long long v : st) res.push_back((int)v);
        return res;
    }
};
