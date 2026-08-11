
class Solution {
private:
    void f(int index, vector<int>& nums,
           vector<int>& arr, vector<vector<int>>& ans) {

        // Every current arr is a valid subset
        ans.push_back(arr);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            arr.push_back(nums[i]);

            f(i + 1, nums, arr, ans);

            arr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Put duplicates next to each other
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> arr;

        f(0, nums, arr, ans);

        return ans;
    }
};
// class Solution {
// private: 
//     void f(int index, int n, vector<int>&arr, vector<int>&nums, set<vector<int>>&st){
//         if(index==n){
//             st.insert(arr);
//             return;
//         }
//         arr.push_back(nums[index]);
//         f(index+1, n, arr, nums, st);

//         arr.pop_back();
//         f(index+1, n, arr, nums, st);
        
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n=nums.size();

//         // ans array which store the all subseq
//         set<vector<int>> st;

//         // which is use to store subseq
//         vector<int> arr;

//         // start index
//         int i=0;

//         f(i,n,arr,nums,st);

//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };

