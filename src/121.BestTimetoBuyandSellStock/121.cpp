/*
 * @Author: Nick Cao
 * @Date: 2021-06-06 11:02:12
 * @LastEditTime: 2021-06-06 12:00:48
 * @LastEditors: Nick Cao
 * @Description: 
 * @FilePath: \LeetCodeLog\src\121. Best Time to Buy and Sell Stock\121.cpp
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_idx = 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            // check lower timing to buy
            if(prices[i] < prices[buy_idx]){
                buy_idx = i;
            } else  if(prices[i] - prices[buy_idx] > profit){  // Update profit when meet higher price
                profit = prices[i] - prices[buy_idx];
            }
            
        }
        return profit;
    }
};