class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        vector<int> dp(n,0);

        int buy = prices[0];

        for(int i=1;i<n;i++){
         buy = min(buy,prices[i]);
         int sell = prices[i] - buy;

         dp[i] = max(dp[i-1],sell);   
        }
        return dp[n-1];
    }
};