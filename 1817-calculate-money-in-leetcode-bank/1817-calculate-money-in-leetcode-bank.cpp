class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int count=1;
        while(n>0){
            int total_amount = count;
            for(int i=0;i<min(7,n);i++){
                sum+=total_amount;
                total_amount++;
            }
            n-=7;
            count++;
        }
        return sum;
    }
};