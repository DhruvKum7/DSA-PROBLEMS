class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int  n = strs.size();
        int  m = strs[0].size();

        int deleted = 0;
        bool count;
        vector<bool>counted(n-1,false);
        for(int i=0;i<m;i++){
            count = false;
            for(int j=0;j<n-1;j++){
                if(counted[j]==false && (strs[j][i]>strs[j+1][i])){
                   count=true;
                    break;
                }
            }
            if(count==true){
                 deleted++;
                continue;
            }else{
                for(int k=0;k<n-1;k++){
                   
                    if(!counted[k] && strs[k][i]<strs[k+1][i]){
                        counted[k]=true;
                    }
                }
                
            }
        }
        return deleted;
    }
};