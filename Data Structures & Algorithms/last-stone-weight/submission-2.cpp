class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int>pq; //max heap
      for(auto & it : stones){
        pq.push(it);
      }
      while(pq.size()>1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        if(x<y){
            pq.push(y-x);
        }
        if(x>y){
            pq.push(x-y);
        }
      }
      if(pq.size()==0){
        return 0;
      }
      return pq.top();
    }
};
