class Solution {
private: 
    void f(int index, int n, vector<int>&arr, vector<int>&nums, vector<vector<int>>&ans){
        if(index==n){
            ans.push_back(arr);
            return;
        }
        // if(index==n && arr.size()==0){
        //     ans.push_back(arr);
        //     return;
        // }
        f(index+1, n, arr, nums, ans);
        arr.push_back(nums[index]);
        f(index+1, n, arr, nums, ans);
        arr.pop_back();
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();

        // ans array which store the all subseq
        vector<vector<int>>ans;

        // which is use to store subseq
        vector<int> arr;

        // start index
        int i=0;

        f(i,n,arr,nums,ans);
        return ans;
    }
};
