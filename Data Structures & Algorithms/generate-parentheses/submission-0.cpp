class Solution {
private: 
    void f(string s, int i, int j, vector<string>&ans, int n){
        if(i==n && j==n){
            ans.push_back(s);
            return; 
        }
        if(i>n || j>n)return;
        if(i<n){
            f(s+'(',i+1,j,ans,n);
        }
        if(j<i){
            f(s+')',i,j+1,ans,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        int i=0;
        int j=0;

        f(s,i,j,ans,n);
        return ans;
    }
};
