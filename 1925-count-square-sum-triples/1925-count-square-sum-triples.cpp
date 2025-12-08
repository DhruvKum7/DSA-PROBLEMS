class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int ans = i*i + j*j;
                int real_ans = sqrt(ans);
                if(real_ans*real_ans==ans){
                    if(real_ans<=n){
                        count+=2;
                    }
                }
            }
        }
        return count;
    }
};