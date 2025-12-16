class Solution {
public:
    const int m = 1e9+7;

    int numberOfWays(string corridor) {
        vector<int> seats;
        for (int i = 0; i < (int)corridor.size(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }

        if (seats.empty() || (seats.size() & 1)) return 0;

        long long ans = 1;
        int prevSecond = seats[1];
        for (int i = 2; i < (int)seats.size(); i += 2) {
            ans = (ans * (seats[i] - prevSecond)) % m;
            prevSecond = seats[i + 1];
        }
        return (int)ans;
    }
};
