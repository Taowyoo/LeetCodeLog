/*
 * @Author: Nick Cao
 * @Date: 2021-06-06 11:48:06
 * @LastEditTime: 2021-06-06 11:59:17
 * @LastEditors: Nick Cao
 * @Description: 
 * @FilePath: \LeetCodeLog\src\121. Best Time to Buy and Sell Stock\121.js
 */


/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let lowest = Infinity;
    let profit = 0;
    for (const price of prices) {
        // update buy timing
        if (price < lowest) {
            lowest = price;
        }
        // update profit
        profit = Math.max(profit, price - lowest);
    }
    return profit;
};