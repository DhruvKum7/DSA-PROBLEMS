class Solution {
public:
    void rotate(string &s ,int b){
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());

    }
    string findLexSmallestString(string s, int a, int b) {
        string result = s;
        queue<string>que;
        unordered_set<string>visited;
        visited.insert(s);
        que.push(s);
        while(!que.empty()){
            string temp = que.front();
            que.pop();

            if(result>temp){
                result = temp;
            }
            string curr = temp;
            for(int i=1;i<curr.length();i=i+2){
                curr[i]=((curr[i]-'0'+ a)%10)+'0';
            }

            if(!visited.count(curr)){
                visited.insert(curr);
                que.push(curr);
            }

            rotate(temp,b);
            if(!visited.count(temp)){
                visited.insert(temp);
                que.push(temp);
            }
        }
        return result;
    }
};