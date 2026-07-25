class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // Use the sliding window technique with a hash map and two pointers.
       // Expand the window by moving `j`. If a duplicate character is found,
       // shrink the window from the left by moving `i` until all characters are unique.
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int> hash;
        int maxi=0;

        while(j<n){
            hash[s[j]]++;
            while(hash[s[j]]>1){
                hash[s[i]]--;
                if(hash[s[i]]==0){
                    hash.erase(s[i]);
                }
                i++;
            }
            maxi=max(maxi,(j-i+1));
            j++;
        }
        return maxi;
    }
};
