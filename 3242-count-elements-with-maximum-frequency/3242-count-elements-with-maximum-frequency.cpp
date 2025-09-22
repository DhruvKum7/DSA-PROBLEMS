class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       vector<int>mp(101,0);
       int minele = 0;
       int count = 0;

       for(int i=0;i<nums.size();i++){
         mp[nums[i]]++;
         if(mp[nums[i]]>minele){
            minele = mp[nums[i]];
            count = minele;
         }else if(mp[nums[i]]==minele){
            count+=minele;
         }
       }
       return count;
    }
};