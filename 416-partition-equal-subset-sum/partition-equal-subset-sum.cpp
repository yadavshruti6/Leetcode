class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();

        int total = accumulate(nums.begin(),nums.end(),0);

        if(total%2 !=0)return false;

        int target = total/2;

        vector<int> dp(target+1,0);
        dp[0]=1;

        for(int num:nums){
            for(int sum = target ; sum>=num ; sum--){
                dp[sum] = dp[sum] || dp[sum-num];
            }
        }
        return dp[target];
    }
};