class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int aHead1Buy = 0, aHead1NotBuy = 0;
        int aHead2Buy = 0, aHead2NotBuy = 0; 
        int currBuy = 0, currNotBuy = 0;
        
        for(int ind = prices.size()-1; ind>=0; ind--){
            currBuy = max(-prices[ind] + aHead1NotBuy,
            0 + aHead1Buy);
            
            currNotBuy = max(prices[ind] + aHead2Buy,
            0 + aHead1NotBuy);

            aHead2Buy = aHead1Buy;
            aHead2NotBuy = aHead1NotBuy;
            aHead1Buy = currBuy;
            aHead1NotBuy = currNotBuy;

        }
        return currBuy;
    }
};
