class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int prev = 0;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                prev  =  0;
            }
            curr+= min(prev,neededTime[i]);
            prev = max(prev,neededTime[i]);
        }
        return curr;
    }
};