class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // step1 sort the nums 
        // step2 using two pointer i and j and traverse j till thhe boundary of same char 
        // step3 store in another vector in form of pair(frequency, element)
        // step4 sort the vector array

        int n=nums.size();
        sort(nums.begin(),nums.end());

        int i=0;
        int j=0;
        vector<pair<int,int>> arr;
        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else if(nums[i]!=nums[j]){
                arr.push_back({j-i , nums[i]});
                i=j;
            }
        }
        arr.push_back({j - i, nums[i]});
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        int m=arr.size();
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
