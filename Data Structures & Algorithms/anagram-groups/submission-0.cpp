class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

// Approach 2:
// Step 1: Store each string in a map as {index, string}.
// Step 2: Sort every string in the map individually.
// Step 3: Traverse using two nested loops.
// Step 4: If strs[i] == strs[j], they belong to the same group.
// Step 5: Check whether index j is still present in the map.
//         If it is present, add the original string at index j to the current group
//         and remove that entry from the map to avoid processing it again.
        int n=strs.size();
        unordered_map<int,string> hash;
        
        for(int i=0; i<n; i++){
            hash[i]=strs[i];
        }

        for(int i=0; i<n; i++){
            sort(strs[i].begin(),strs[i].end());
        }
        
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            vector<string>brr;
            for(int j=i; j<n; j++){
                if(strs[i]==strs[j]){
                    if(hash.find(j)!=hash.end()){
                       brr.push_back(hash[j]);
                       hash.erase(j);
                    }
                }
            }
            if(brr.size()>0){
               ans.push_back(brr);
            }
        }
        return ans;
    }
};
