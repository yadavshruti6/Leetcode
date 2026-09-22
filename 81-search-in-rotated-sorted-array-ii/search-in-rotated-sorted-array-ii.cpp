class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int low = 0;
        int hi = n-1;

        while(low<=hi){
            int mid = low + (hi-low)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[mid] == nums[low] && nums[mid] == nums[hi]){
                low++;
                hi--;
                continue;
            }

            if(nums[mid]>=nums[low]){
                if(nums[low] <= target && nums[mid]> target){
                    hi = mid -1;
                } 
                else{
                    low = mid +1;
                }
            }
            else{
                if(nums[hi] >= target && nums[mid] < target){
                   low = mid +1;
                } 
                else{
                     hi = mid -1;
                }
            }
        }
        return false;
    }
};