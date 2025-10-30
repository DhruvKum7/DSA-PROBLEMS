class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int curr = 0;
        int prev = 0;
        long long ope = 0;
        for(auto &i : target){
            curr = abs(i);
            if(abs(prev) < abs(curr)){
                ope+=abs(curr-prev);
            }
            prev = curr;
        }
        return ope;
    }
};