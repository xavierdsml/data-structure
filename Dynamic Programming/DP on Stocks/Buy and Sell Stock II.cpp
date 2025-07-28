class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>aHead(2, 0), curr(2, 0);
        
        int aHeadNotBuy, aHeadBuy, currNotBuy, currBuy;
        aHeadNotBuy = aHeadBuy = 0;
        
        for(int index = prices.size()-1; index>=0; index--){
            currBuy = max(-prices[index] + aHeadNotBuy, 
            0 + aHeadBuy);

            currNotBuy = max(prices[index] + aHeadBuy,
            0 + aHeadNotBuy);
    
            aHeadNotBuy = currNotBuy;
            aHeadBuy = currBuy;
        }
        return aHeadBuy;
    }
};
