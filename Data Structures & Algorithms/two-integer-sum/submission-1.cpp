class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //m1 using two nested loop . tc->n^2
        //m2 sort the array then take twopointer left=0, right=n-1, check their sum >/< target , then traverse pointer . tc-> nlogn + n,
        // m3 use map and check target -current is present in map or not , tc->n, sc-> n
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
