// Source : https://leetcode.com/problems/bulb-switcher/
// Author : Zhonghuan Gao
// Date   : 2018-07-20

/**********************************************************************************
*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Input: 3
Output: 1 
Explanation: 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*
**********************************************************************************/

/*
7 盏灯
0 0 0 0 0 0 0

1 1 1 1 1 1 1
1 0 1 0 1 0 1
1 0 0 0 1 1 1
1 0 0 1 1 1 1
1 0 0 1 0 1 1
1 0 0 1 0 0 1
1 0 0 1 0 0 0
*/

/*
 * 灯泡次数
 * 设 n = 36，n 的因子有 (1,36), (2,18), (3,12), (4,9), (6,6)
 * 第 n 次后除了平方根数，其他次数的灯泡都被括号中相反的次数抵消掉了
 * 故可以简化为求 1-n 之间完全平方数的个数 
 */
class Solution {
public:
    int bulbSwitch(int n) {
        int res = 1;
        while (res * res <= n) ++res;
        return res - 1;
    }
};
