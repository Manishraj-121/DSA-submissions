class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<int, int> hash;

        for (int i = 0; i < n; i++) {
            hash[nums[i]] = i;
        }
        set<vector<int>> st;   // to remove duplicate triplets
        for (int i = 0; i < n-2; i++) {
            for (int j = i + 1; j < n-1; j++) {
                int target = (-1) * (nums[i] + nums[j]);
                if (hash.find(target) != hash.end() && hash[target] != i && hash[target] != j && hash[target] > j){
                    vector<int> arr;
                    arr.push_back(nums[i]);
                    arr.push_back(nums[j]);
                    arr.push_back(target);
                    sort(arr.begin(), arr.end());
                    st.insert(arr);
                   // ans.push_back(arr);
                }
            }
          
        }
       for (auto &it : st){
            ans.push_back(it);
       }

        return ans;
    }
};
