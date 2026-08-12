class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // m1 using 3 nested loop find the sum=0 . tc->n^3
        // m2 using map and then use 2 nested loop tc->n^2 , sc->n
        // m3 sort the array take 3 pointer first at index 0, second at first+1, third at n-1 , check target= -1*nums[first] check implement two pointer in sorted array su m is equal to target  or not , or update second and third accordingly, once we get second>=third then increment in first by one unit , this process will be continue till the when first excede the n-1
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
                }
            }
          
        }
       for (auto &it : st){
            ans.push_back(it);
       }

        return ans;
    }
};
