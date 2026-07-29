class Solution {
public:
    int characterReplacement(string s, int k) {
       int n=s.size();
       int i=0;
       int j=0;
       unordered_map<char,int> hash;
       int maxi= INT_MIN;
       int ans= INT_MIN;

       while(j<n){
        hash[s[j]]++;
        maxi=max(maxi,hash[s[j]]);
        
        while((j-i+1 - maxi) > k  ){
          hash[s[i]]--;
          i++;
        }
        ans=max(ans,j-i+1);
        j++;
       } 
       return ans;
    }
};
