class Solution {
public:
    int characterReplacement(string s, int k) {
      //m1 brute force in which i will track all possible substring and then check th max freq element with the help of map , j-i+1 - max freq ele should equal to k at that time maximize th substring. tc->n^2, sc O(n)
      //m2 using sliding window with map, map is use to find the maximum freq of any one element that will be subtract from j-i+1 that must be the no of diff element in array  , and it must be equal to k , at that time find the maximum length of substring if lesser then srink size of window otherwise increase size of window. tc->n, sc->n.
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
