class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n=nums.size();
     vector<int> pre;
     vector<int> post;
     int temp1=1;
     int temp2=1;


     for(int i=0; i<n; i++){
        temp1*=nums[i];
        temp2*=nums[n-1-i];
        pre.push_back(temp1);
        post.push_back(temp2);
     }
     reverse(post.begin(),post.end());

     vector<int> ans;
     for(int i=0; i<n; i++){
        if(i==0){
            ans.push_back(post[i+1]);
        }
        else if(i==n-1){
            ans.push_back(pre[i-1]);
        }
        else{
            ans.push_back(pre[i-1]*post[i+1]);
        }
     }
     return ans;
    }
};
