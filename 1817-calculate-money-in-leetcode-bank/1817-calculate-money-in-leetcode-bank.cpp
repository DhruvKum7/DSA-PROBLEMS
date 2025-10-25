class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;
        int first = 28;
        int last = 28+(terms-1)*7;

        int result = terms * (first+last)/2;

        int start_system = 1+ terms;
        for(int i=1;i<=(n%7);i++){
            result+=start_system;
            start_system++;
        }
        return result;
    }
};