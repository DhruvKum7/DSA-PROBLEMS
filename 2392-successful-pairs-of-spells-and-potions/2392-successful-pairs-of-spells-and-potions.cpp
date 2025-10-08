class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       int n = spells.size();
       int m = potions.size();

       sort(potions.begin(),potions.end());

       vector<int>result;
       for(int i=0;i<n;i++){
        int spell = spells[i];
        long long ans = ceil((1.0*success)/spell);

        if(ans>potions[m-1]){
            result.push_back(0);
            continue;
        }

        int index = lower_bound(potions.begin(),potions.end(),ans)-potions.begin();

        result.push_back(m-index);
       } 
       return result;
    }
};