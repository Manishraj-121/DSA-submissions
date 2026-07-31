class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       // m1 Kedans algo
       // naieve sol using two nested loop tc-> O(n^2)

       int n=nums.size();
       int sum=0;
       int maxi=INT_MIN;
       int i=0;
       int j=0;

       while(j<n){
        sum=sum+nums[j];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
            i=j+1;
        }
        j++;
       }
       return maxi;
    }
};
