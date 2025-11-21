class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<int>st;
        int n = s.length();
        for(auto &i : s){
            st.insert(i);
        }
        long long result = 0;
        vector<pair<int,int>>vec;
        for(auto &j : st){
            int first = -1;
            int last  = -1;
            for(int i=0;i<n;i++){
                if(s[i]==j){
                    if(first==-1){
                        first = i;
                    }
                    last = i;
                }
            }
            vec.push_back(make_pair(first,last));
        }
        
        for(auto &v : vec){
            int fir = v.first;
            int sec = v.second;
            unordered_set<int>set;
            for(int i=fir+1;i<sec;i++){
                set.insert(s[i]);
            }
            result+=set.size();
        }
        return result;
    }
};