class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char>letter;
        for(int i = 0;i<n;i++){
            letter.insert(s[i]);
        }int result = 0;
        for(auto &j : letter){
            int left = -1;
            int right = -1;
            for(int i = 0;i<n;i++){
                if(s[i]==j){
                    if(left==-1){
                        left=i;
                    }

                    right = i;
                }
            }
            unordered_set<char>st;
            for(int middle = left+1;middle<=right-1;middle++){
                st.insert(s[middle]);
            }
            result+=st.size();
        }
        return result;
    }
};