class Solution {
public:
    bool isValid(string s) {
        // m1 in which i will simply traverse the string and then check (),{},[] then erase(i,2);
        // m2 using stack try to compare the adjacent parenthesis
        int n=s.size();
        stack<char>st;

        for(int i=0; i<n; i++){
            if(!st.empty() && ((st.top()=='('&& s[i]==')') || (st.top()=='{'&& s[i]=='}') || (st.top()=='['&& s[i]==']'))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size()==0;
    }
};
