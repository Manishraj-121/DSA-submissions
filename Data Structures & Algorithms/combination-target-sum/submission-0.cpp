class Solution {
private:
    void f(int index, int sum, vector<int>&arr, vector<vector<int>>&ans, int n, vector<int>&nums, int target){
        if(sum==target){
            ans.push_back(arr);
            return; 
        }
        if(index==n || sum>target){
            return; 
        }

        f(index+1, sum, arr, ans, n, nums, target);
        arr.push_back(nums[index]);
        f(index, sum+nums[index], arr, ans, n, nums, target);
        arr.pop_back();
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        vector<int> arr;
        vector<vector<int>>ans;
        int i=0;

        f(i, sum, arr, ans, n, nums, target);
        return ans;
    }
};
