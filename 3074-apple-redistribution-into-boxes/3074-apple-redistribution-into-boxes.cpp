class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
      priority_queue<int>pq;
      for(auto &i : capacity){
        pq.push(i);
      } 
      int sum = accumulate(apple.begin(),apple.end(),0); 
      int count = 0;
      while(!pq.empty() && sum>0){
        int first = pq.top();
        pq.pop();
        sum = sum-first;
        count++;
      }
      return count;
    }
};