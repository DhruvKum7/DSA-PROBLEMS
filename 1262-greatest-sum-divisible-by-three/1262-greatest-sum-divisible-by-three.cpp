class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
      int n = nums.size();
      vector<int>round_1;
      vector<int>round_2;
      int sum = 0;
      for(auto &i : nums){
        if(i%3==1){
            round_1.push_back(i);
        }
        if(i%3==2){
            round_2.push_back(i);
        }
        sum+=i;
      }  

      sort(round_1.begin(),round_1.end());
      sort(round_2.begin(),round_2.end());
      if(sum%3==0){
        return sum;
      }
      int result = INT_MAX;
      if(sum%3==1){
        int first = (round_1.size()>=1)? round_1[0] : (int)1e9;
        int second = (round_2.size()>=2)?round_2[0]+round_2[1]:(int)1e9;

        result = min(result,min(first,second));
      }
      if(sum%3==2) {
        int first = (round_2.size()>=1)? round_2[0] : (int)1e9;
        int second = (round_1.size()>=2)?round_1[0]+round_1[1]:(int)1e9;

        result = min(result,min(first,second));
      }
      return (sum-result);
    }

};