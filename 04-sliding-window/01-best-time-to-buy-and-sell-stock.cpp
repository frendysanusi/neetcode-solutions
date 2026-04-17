class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int buy = 0;
        int sell = 0;

        while (sell < prices.size()) {
            if ((sell + 1 < prices.size()) && (prices[sell + 1] >= prices[sell])) {
                sell ++;
            }
            else {
                int currProfit = prices[sell] - prices[buy];
                if (currProfit > max) {
                    max = currProfit;
                }
                if (prices[sell + 1] < prices[buy]) {
                    buy = sell + 1;
                }
                sell ++;
            }
        }

        return max;
    }
};
