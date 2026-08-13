class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        
        int carry=1;
        for(int i=n-1; i>=0; i--){

            int x=digits[i]+carry;
            if(x>9){
                carry=x/10;
                x=x%10;
            }
            else{
                carry=0;
            }
            digits[i]=x;
        }
        if(carry>0){
            ans.push_back(carry);
        }
        for(int i=0; i<n; i++){
            ans.push_back(digits[i]); 
        }
        return ans;
    }
};
