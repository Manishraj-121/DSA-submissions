class Solution {
public:
    int maxArea(vector<int>& heights) {
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
