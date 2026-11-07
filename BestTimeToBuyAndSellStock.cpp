class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 
        Best Time to Buy and Sell Stock
        
        initialize with the first index 
        if the profit is -ve then move the pointer to the current index
        if there is no profit keep on moving to the end and when the end element is reached return 0 profit */
        int pointer = prices[0];
        int maxProfit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] - pointer <= 0){
                pointer = prices[i];
            }
            else if(prices[i] - pointer > maxProfit){
                maxProfit = prices[i] - pointer;
            }
        }

        return maxProfit;
    }
};
