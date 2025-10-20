class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        vector<int>vec;
        int ans=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="++X"){
                ans=ans+1;
            }
            if(operations[i]=="X++"){
                ans=ans+1;
            }
            if(operations[i]=="X--"){
                ans=ans-1;
            }
            if(operations[i]=="--X"){
                ans=ans-1;
            }
        }
        return ans;
    }
};