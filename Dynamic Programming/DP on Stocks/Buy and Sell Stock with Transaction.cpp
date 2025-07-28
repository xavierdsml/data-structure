class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int aHeadBuy = 0, aHeadNotBuy = 0;
        int currBuy = 0, currNotBuy = 0;
        
        for(int ind = prices.size()-1; ind>=0; ind--){
            currBuy = max(-prices[ind] + aHeadNotBuy,
            0 + aHeadBuy);

            currNotBuy = max(prices[ind] - fee + aHeadBuy,
            0 + aHeadNotBuy);

            aHeadBuy = currBuy;
            aHeadNotBuy = currNotBuy;
        }
        return currBuy;
    }
};
