class Solution {
public:
    int findMin(vector<int>& nums) {

       int n = nums.size();

       int low = 0;
       int hi = n - 1;

       while( low < hi ){

        int mid = low + (hi - low)/2;

        if(nums[low] < nums[hi]){
            return nums[low];
        }

        if(nums[mid] >= nums[low]){
            low = mid + 1;
        }
        else{
            hi = mid;
        }

       } 
       return nums[low];
    }
};