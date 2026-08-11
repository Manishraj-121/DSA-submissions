class Solution {
public:
    void function(vector<vector<int>>& ans, vector<int>& brr,
                  int start, int sum, vector<int>& candidates, int target) {

        if (sum == target) {
            ans.push_back(brr);
            return;
        }

        if (sum > target) return;

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate values at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (sum + candidates[i] > target)
                break;

            brr.push_back(candidates[i]);

            function(ans, brr, i + 1,
                     sum + candidates[i], candidates, target);

            brr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> brr;

        function(ans, brr, 0, 0, candidates, target);

        return ans;
    }
};
// class Solution {
// private:
//     void f(int index, int sum, vector<int>&arr, set<vector<int>>&st, int n, vector<int>&candidates, int target){
//         if(sum==target){
//             st.insert(arr);
//             return; 
//         }
//         if(index==n || sum>target){
//             return; 
//         }
//         arr.push_back(candidates[index]);
//         f(index+1, sum+candidates[index], arr, st, n, candidates, target);
//         arr.pop_back();
//         f(index+1, sum, arr, st, n, candidates, target);
        
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         int n=candidates.size();
//         int sum=0;
//         vector<int> arr;
//         set<vector<int>>st;
//        // vector<vector<int>>ans;
//         int i=0;

//         f(i, sum, arr, st, n, candidates, target);
//          vector<vector<int>> ans(st.begin(), st.end());
//         return ans;

//     }
// };