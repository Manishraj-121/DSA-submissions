class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // m1 sort the array then traverse the array
        
        int n=nums.size();
        if(n==0)return 0;
        sort(nums.begin(),nums.end());
        int i=0; 
        int j=1;
        int count=1;
        int maxi=1;

        while(j<n){
            if(nums[i]+1==nums[i+1]){
                count++;
                i++;
                j++;
            }
            else if(nums[i]==nums[i+1]){
                i++;
                j++;
            }
            else{
                count=1;
                i++;
                j++;
            }
            maxi=max(maxi,count);
        }


return maxi;





        //m2 using map
        // int n=nums.size();
        // unordered_map<int, int> hash;
        
        // for(int i=0; i<n; i++){
        //     hash[nums[i]]++;
        // }
        // sort(nums.begin(),nums.end());

        // int count=0;
        // int maxi=0;

        // for(int i=0; i<n; i++){
        // if(hash.find(nums[i]+1)!=hash.end()){
        //     count++;
        //     maxi=max(maxi,count);
        // }
        // else{
        //     count=1;
        // }
        // }
        // return maxi;
    }
};
