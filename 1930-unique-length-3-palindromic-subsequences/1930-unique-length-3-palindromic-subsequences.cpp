class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>st;
        int n = s.length();
        for(auto &i : s){
            st.insert(i);
        }
        long long result=0;
        for(auto &j : st){
            int first = -1;
            int last = -1;
            for(int i=0;i<n;i++){
                if(s[i]==j){
                    if(first==-1){
                        first=i;
                    }
                     last=i;
                }
               
            }

            unordered_set<char>st_2;
            for(int k = first+1;k<last;k++){
                st_2.insert(s[k]);
            }
            result+=st_2.size();
        }
        return result;
    }
};