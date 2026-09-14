class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

       int n =nums.size();

       int left=0;
       int zeros=0;
       int maxl=0;

       for(int right=0;right<n;right++){
        if(nums[right]==0){
            zeros++;
        }
        while(zeros>k){
            if(nums[left]==0){
                zeros--;
            }
            left++;
        }
        maxl = max(maxl , right - left + 1);
       } 
       return maxl;
    }
};