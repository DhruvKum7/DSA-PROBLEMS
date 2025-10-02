class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        long long ans = 0;
        while(numBottles>=numExchange){
            ans+=numExchange;
            numBottles-=numExchange;
            numExchange++;
            numBottles++;

        }
        ans+=numBottles;
        return ans;
    }
};