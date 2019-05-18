// Source : https://leetcode.com/problems/valid-perfect-square/
// Author : Zhonghuan Gao
// Date   : 2019-05-18

/********************************************************************************** 
*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*               
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一：二分法
     */
    bool isPerfectSquare(int num) {
        long long low = 1, high = num, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mid * mid == num) return true;
            else if (mid * mid < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
