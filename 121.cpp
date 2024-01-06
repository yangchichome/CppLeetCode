class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int minPrice = INT_MAX;
        int maxPrice = INT_MIN;

        for (int x : prices) {
            if (x <= minPrice) {
                minPrice = x;
                maxPrice = x;
            } else {
                maxPrice = max(maxPrice, x);
            }
            profit = max(profit, maxPrice - minPrice);
        }

        return profit;
    }
};
