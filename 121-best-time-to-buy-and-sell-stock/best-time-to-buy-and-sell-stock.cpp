class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = prices[0];
        int sell = 0;

        for(int i = 1; i < prices.size(); i++) {

            int p = prices[i];

            sell = max(sell, p - buy);

            buy = min(buy, p);
        }

        return sell;
    }
};