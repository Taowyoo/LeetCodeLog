/*
 * @Author: Nick Cao
 * @Date: 2021-06-06 14:18:45
 * @LastEditTime: 2021-06-06 14:25:19
 * @LastEditors: Nick Cao
 * @Description: 
 * @FilePath: \LeetCodeLog\src\121. Best Time to Buy and Sell Stock\121.rs
 */

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut buy = prices[0];
        let mut profit = 0;
        for price in prices.iter() {
            if buy > *price {
                buy = *price;
            } else if profit < *price - buy {
                profit = *price - buy;
            }
        }
        profit
    }
}