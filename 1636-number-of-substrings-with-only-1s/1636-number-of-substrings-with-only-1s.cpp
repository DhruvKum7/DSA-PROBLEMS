class Solution {
public:
    const int m = 1000000007;
    int numSub(string s) {
        long long count=0;
        long long result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                ;
                count=0;
            }else{
                count++;
                result+=count;
            }
        }
        return (result % m);
    }
};