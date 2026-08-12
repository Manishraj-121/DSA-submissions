class Solution {
public:
    int maxProfit(vector<int>& prices) {
//m1 solve using two nested loop tc->n^2
//m2 traverse right to left maintain a variable maxi element and then check maximize temp=maxi-current element it wiil continue for each element.  tc->n
//m3 solve with the help of dp , in which take a miniele variable and maxiSellng variable is equal to max(maxSelling, (currentEle - miniele)).
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
