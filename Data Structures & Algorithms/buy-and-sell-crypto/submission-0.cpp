class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // in which we traverse from right to  left maintain the maxi element and simulteniously check the diff b/w current ele and store it in 2nd maxi variable and return 2nd max variable and return 2nd max
        int n=prices.size();
        int maxi_1=INT_MIN;
        int maxi_2=INT_MIN;

        for(int i=n-1; i>=0; i--){
            maxi_1=max(maxi_1, prices[i]);
            maxi_2=max(maxi_2, abs(maxi_1 - prices[i]));
        }
        return maxi_2;
    }
};
