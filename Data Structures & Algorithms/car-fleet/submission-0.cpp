class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // first of all i will take a vector that store pair<position, speed>
        // now i will sort the array and initiallize maxi variable with int_min
        // itrate from right to left and find time to reach target and check it is if greater then it is fleet of previous one other wise increase count value by one unit 

        int n=position.size();
        vector<pair<int,int>> arr;
    
        for(int i=0; i<n; i++){
            arr.push_back({position[i],speed[i]});
        }

        sort(arr.begin(),arr.end());
        
        double temp=-1.0;
        int count=0;

        for(int i=n-1; i>=0; i--){
            float time=(double)(target-arr[i].first)/arr[i].second;
            // merge current car in fleet
            if(time>temp){
                temp=time;
                count++;
            }
        }
        return count;
    }
};
