class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>t = triangle;
        for(int i = n-2;i>=0;i--){
            for(int col = 0;col<=i;col++){
                t[i][col]=t[i][col]+min(t[i+1][col] , t[i+1][col+1]);
            }
        }
        return t[0][0];
    }
};