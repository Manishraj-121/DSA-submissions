class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
       vector<pair<float,vector<int>>>arr;
        vector<vector<int>>ans;

        for (int i = 0; i < n; i++) {
            float x = pow((points[i][0]*points[i][0] + points[i][1]*points[i][1]) , (1.0 / 2));
            arr.push_back({x, points[i]});
        }
        sort(arr.begin(),arr.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
