class Solution {
public:
    int maxArea(vector<int>& heights) {
        //m1 using 2 nested loop and maximize ((j-i)*min(num[i],num[j])) tc->n^2
        //m2 using two pointer sliding index left at 0 and right at n-1 and traverse , traverse index which is smaller. 
        

        int n=heights.size();
        int i=0;
        int j=n-1;
        int maxi = INT_MIN;

        while(i<j){
            maxi=max(maxi,(j-i)*(min(heights[i],heights[j])));
            if(heights[i]<=heights[j]){
                i++;
            }
            else if(heights[i]>heights[j]){
                j--;
            }
        }
        return maxi;
    }
};