class Solution {
public:
    int maxProfit(vector<int>& prices) {
// Traverse the array from right to left while maintaining the maximum element.
// Simultaneously, calculate the difference between the current element and the maximum element,
// and store the maximum difference found so far in another variable.
// Finally, return the maximum difference.
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
