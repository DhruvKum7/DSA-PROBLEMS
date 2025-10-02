class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       long long ans = 0;
        while(numBottles>=numExchange){
            ans+=numExchange;
            numBottles-=numExchange;
            // numExchange++;
             numBottles++;

        }
        ans+=numBottles;
        return ans; 
    }
};