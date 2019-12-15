// Source : https://leetcode.com/problems/factorial-trailing-zeroes/
// Author : Zhonghuan Gao
// Date   : 2019-12-15

/********************************************************************************** 
*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Note: Your solution should be in logarithmic time complexity.
*               
**********************************************************************************/

/**
 * 题意：
 * 求 1-n 的阶乘数末尾有多少个0
 */
class Solution {
public:
    /**
     * 解法一：
     * 求一个数的阶乘末尾0的个数，也就是要找乘数中 10 的个数，而 10 可分解为2和5，
     * 而2的数量又远大于5的数量（比如1到 10 中有2个5，5个2），那么此题即便为找出5的个数。
     * 仍需注意的一点就是，像 25，125，这样的不只含有一个5的数字需要考虑进去
     */
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }

    /**
     * 解法一递归解法
     */
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
