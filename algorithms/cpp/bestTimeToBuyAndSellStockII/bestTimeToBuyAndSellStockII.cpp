// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Zhonghuan Gao
// Date   : 2019-04-05

/********************************************************************************** 
**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 贪心法
     * 思路: 基本思路与120题类似，只是当当前元素小于它的上一个元素时，
     * 在当前位置设置一个哨兵，那么下一次求局部最大值就从哨兵位置开始遍历
     */
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len  < 2) return 0;

        int maxProfit = 0, subMaxProfit = 0, pos = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] < prices[i-1]) {
                pos = i;
                maxProfit += subMaxProfit;
                subMaxProfit = 0;
                continue;
            }
            for (int j = pos; j < i; j++) {
                if (prices[i] - prices[j] > subMaxProfit) {
                    subMaxProfit = prices[i] - prices[j];
                }
            }
        }
        return maxProfit + subMaxProfit;
    }

    /**
     * 贪心法
     */
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1, len = prices.size(); i < len; ++i)
          maxProfit += max(prices[i] - prices[i - 1], 0);
        return maxProfit;
    }
};
