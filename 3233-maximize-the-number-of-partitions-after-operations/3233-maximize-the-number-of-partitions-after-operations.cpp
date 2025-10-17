class Solution {
public:
    string s;
    int k;
    unordered_map<long long, int> memo;

    int dfs(int idx, int mask, bool canChange) {
        if(idx == s.size()) return 0;
        long long key = ((long long)idx << 27) | ((long long)mask << 1) | canChange;
        if(memo.count(key)) return memo[key];

        int curChar = s[idx] - 'a';
        int newMask = mask | (1 << curChar);
        int res;
        if(__builtin_popcount(newMask) > k)
            res = 1 + dfs(idx+1, 1 << curChar, canChange);
        else
            res = dfs(idx+1, newMask, canChange);

        if(canChange){
            for(int c=0;c<26;c++){
                if(c == curChar) continue;
                int mask2 = mask | (1 << c);
                if(__builtin_popcount(mask2) > k)
                    res = max(res, 1 + dfs(idx+1, 1 << c, false));
                else
                    res = max(res, dfs(idx+1, mask2, false));
            }
        }

        return memo[key] = res;
    }

    int maxPartitionsAfterOperations(string _s, int _k){
        s = _s;
        k = _k;
        memo.clear();
        return dfs(0, 0, true) + 1;
    }
};