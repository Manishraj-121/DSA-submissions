class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        
        // meeting point
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            
            // terminating condition
            if(slow==fast)break;
        }
        slow = 0;
        // finding meeting index
         while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
