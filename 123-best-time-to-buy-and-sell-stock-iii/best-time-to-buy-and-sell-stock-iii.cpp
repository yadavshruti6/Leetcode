class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        
        int buy1 = -prices[0];
        int sell1 = 0;

        int buy2 = -prices[0];
        int sell2 = 0;

        for(int i=0;i<n;i++){

            int p = prices[i];

            buy1 = max(buy1, -p);
            sell1 = max(sell1 , buy1 + p);

            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);

        }
        return sell2;
    }
};