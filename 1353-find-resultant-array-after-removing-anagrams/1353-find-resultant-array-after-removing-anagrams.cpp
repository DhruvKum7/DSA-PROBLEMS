class Solution {
public:
    bool solve(string s_1 , string s_2){
       int arr[26]={0};
        for(auto &i : s_1){
            arr[i-'a']++;
        }
        for(auto &i : s_2){
            arr[i-'a']--;
        }
        for(auto & i : arr){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string>result;
        result.push_back(words[0]);

        for(int i=1;i<n;i++){
            if(solve(words[i],result.back())==false){
                result.push_back(words[i]);
                
            }
        }
        return result;
    }
};