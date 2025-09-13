class Solution {
public:
    int maxFreqSum(string s) {
        int vowmax = 0;
        int constmax= 0;
        unordered_map<char,int>mp;
        string vow = "aeiou";
        for(auto &i : s){
            mp[i]++;
        }
        for(auto &i : mp){
            if(vow.find(i.first)!=string::npos){
                vowmax=max(i.second,vowmax);
            }else{
                constmax = max(i.second,constmax);
            }
        }
        return vowmax+constmax;
    }
};