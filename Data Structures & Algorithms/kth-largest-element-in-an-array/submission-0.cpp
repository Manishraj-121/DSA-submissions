class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size()-1;
        priority_queue<int> mheap;

        for(int i=0; i<=n; i++){
            mheap.push(nums[i]);
        }
        int count=0;
        int y;
        while(count!=k){
            y=mheap.top();
            mheap.pop();
            count++;
        }
        return y;
    }
};
