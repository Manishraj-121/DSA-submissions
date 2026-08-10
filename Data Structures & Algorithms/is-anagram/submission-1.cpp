class Solution {
public:
    bool isAnagram(string s, string t) {
        // m1 use two map and compare both map. tc->2n  , sc->2n
        // m2 using map push all element of 1st string , now traverse 2nd str and if current of 2nd str is present in map then reduce freq by one and similarly if their freq become 0 then remove this key from map. tc->2n , sc-> n.
        int n=s.size();
        if(s.size()!=t.size())return false;

        unordered_map<char,int> hash;

        for(int i=0; i<n; i++){
            hash[s[i]]++;
        } 
        for(int i=0; i<n; i++){
            if(hash.find(t[i])!= hash.end()){
                hash[t[i]]--;
                if(hash[t[i]]==0){
                    hash.erase(t[i]);
                }
            }
        } 
        if(hash.size()>0)return false;
        return true;
    }
};
