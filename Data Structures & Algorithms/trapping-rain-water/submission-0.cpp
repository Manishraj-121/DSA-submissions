class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre;
        vector<int> post;
        int maxi=0;
        int maxi2=0;

        for(int i=0; i<n; i++){
            maxi=max(maxi,height[i]);
            pre.push_back(maxi);
            maxi2=max(maxi2,height[n-1-i]);
            post.push_back(maxi2);
        }
        reverse(post.begin(),post.end());

        int water=0;
        for(int i=0; i<n; i++){
           water = water + (min(pre[i],post[i])-height[i]);
        }
        return water;
    }
};
