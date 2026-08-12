class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //m1 using two nested loop then find the sum fo two value == target tc->n2
        //m2 using two pointer(it is sorted), left=0, right=n-1 then check the sum and traverse accordingly tc->n 
        //m3 using binary search i will find for each element of an array temp=target-nums[i] , now implement binary search, tc->n*logn
        // m4 using map store all element in it and then traverse array and check target-nums[i] is present or not then return index 
        int n=numbers.size();
        vector<int> ans;
        int i=0;
        int j=n-1;
        int sum=0;
        
        while(i<j){
            sum = numbers[i]+numbers[j];
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            else if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};
