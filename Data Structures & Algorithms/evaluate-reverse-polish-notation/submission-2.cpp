class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(!st.empty() && (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();

                if(tokens[i]=="+"){
                    st.push(x+y);
                }
                else if(tokens[i]=="-"){
                    st.push(y-x);
                }
                else if(tokens[i]=="*"){
                    st.push(x*y);
                }
                else if(tokens[i]=="/"){
                    st.push(y/x);
                }
            }
            else{
              st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
