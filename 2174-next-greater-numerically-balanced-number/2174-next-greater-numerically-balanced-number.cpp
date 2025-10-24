class Solution {
public:
    vector<int> digitcount{0,1,2,3,4,5,6,7,8,9};

    int backtrack(int n, int curr, int digit){
        if(digit==0){
            for(int i = 1; i <= 9; i++){
                if(digitcount[i] != 0 && digitcount[i] != i){
                    return 0;
                }
            }
            return curr > n ? curr : 0;
        }
        int result = 0;
        for(int i = 1; i <= 9; i++){
            if(digitcount[i] > 0 && digitcount[i] <= digit){
                digitcount[i]--;
                result = backtrack(n, curr * 10 + i, digit - 1);
                digitcount[i]++;
            }
            if(result != 0){
                break;
            }
        }
        return result;
    }

    int nextBeautifulNumber(int n) {
        int initial_len = to_string(n).length();
        int result = backtrack(n, 0, initial_len);
        if(result == 0){
            result = backtrack(n, 0, initial_len + 1);
        }
        return result;
    }
};
