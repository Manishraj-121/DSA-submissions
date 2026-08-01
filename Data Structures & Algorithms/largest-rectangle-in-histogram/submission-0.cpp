class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        // M2:
        // 1. Store the left boundary as (Previous Smaller Element index + 1).
        // 2. Store the right boundary as (Next Smaller Element index - 1).
        // 3. For each bar, calculate:
        //      width = rightBoundary[i] - leftBoundary[i] + 1
        //      area = width * heights[i]
        // 4. Return the maximum area.
        int n=heights.size();
        int maxi=INT_MIN;
        vector<int> pse(n);
        stack<int> st1;  // stores indices

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && heights[st1.top()] >= heights[i]) {
                st1.pop();
            }

            pse[i] = st1.empty() ? 0 : st1.top()+1;

            st1.push(i);
        }

        vector<int> nse(n);
        stack<int> st2;  // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }

            nse[i] = st2.empty() ? n - 1 : st2.top()-1;

            st2.push(i);
        }

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, (abs(pse[i] - nse[i])+1) * heights[i]);
        }

        return maxi;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         // m1 brute force using two nested loop tc->O(n^2)
//         int n=heights.size();
//         int area=0;

//         int maxi=INT_MIN;
//         int maxi2=INT_MAX;

//         for(int i=0; i<n; i++){
//             int mini=INT_MAX;
//             for(int j=i; j<n; j++){
//                 mini=min(mini,heights[j]);
//                 area=(j-i+1)*mini;
//                 maxi=max(maxi,area);
//             }

//         }
//         return maxi;
//     }
// };
