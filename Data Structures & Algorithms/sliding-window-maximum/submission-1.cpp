class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // m1 brute force
        // m2 using priority queue
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second <= i-k){
                pq.pop();
            }
            if(i>=k-1){
                ans.push_back(pq.top().first);
            }
        }

        return ans;

        // m3 using two pointer and map
        // int n=nums.size();
        // vector<int> ans;
        // int i=0;
        // int j=0;
        // int maxi= INT_MIN;
        // unordered_map<int,int> hash;

        // while(j<n){
        //     if(j-i+1<k){
        //         hash[nums[j]]++;
        //         maxi=max(maxi,nums[j]);
        //         j++;
        //     }
        //     else if(j-i+1>=k){
        //         maxi=max(maxi,nums[j]);
        //         ans.push_back(maxi);
        //         i++;
        //         j++;
        //     }
        // }
        // return ans;
    }
};
