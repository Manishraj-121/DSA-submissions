class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> hash;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(hash.find(target-nums[i])!=hash.end()){
                ans.push_back(hash[target-nums[i]]);
                ans.push_back(i);
            }
            else{
                hash[nums[i]]=i;
            }
        }
        return ans;
    }
};
