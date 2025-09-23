class Solution {
public:
    vector<string>gettoken(string &version1){
        stringstream ss(version1);
        string token ="";
        vector<string>tokens;
        while(getline(ss , token , '.')){
tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = gettoken(version1);
        vector<string>v2 = gettoken(version2);

        int n = v1.size();
        int m = v2.size();

        int i=0;
        int j=0;
        while(i<n || j<m){
            int a = i<n?stoi(v1[i]):0;
            int b = j<m?stoi(v2[j]):0;

            if(a<b){
                return -1;
            }else if(a>b){
                return 1;
            }else{
                i++;
                j++;
            }
        }
        return 0;

    }
};