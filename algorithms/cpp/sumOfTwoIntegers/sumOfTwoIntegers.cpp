// Source : https://leetcode.com/problems/sum-of-two-integers/
// Author : Zhonghuan Gao
// Date   : 2019-12-23

/********************************************************************************** 
*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1
*               
***********************************************************************************/

/**
 * 题意：
 * 两数求和，不用 +、- 操作符
 */
class Solution {
public:
    /**
     * 解法一：
     * 1.先忽略进位求两个数的和（即a ^ b）
     * 2.再计算两个数的进位（即a & b），并将进位左移1位
     * 循环（将1和2得到的进行第一步和第二步操作），直到没有进位
     */
    /* 错误，未考虑负数左移
    int getSum(int a, int b) {
        int sum = a;
        while (b != 0) {
            sum = a ^ b; // calculate sum of a and b without thinking the carry
            b = (a & b) << 1; // calculate the carry
            a = sum; // add sum(without carry) and carry
        }
        return sum;
    }
    */

    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};
