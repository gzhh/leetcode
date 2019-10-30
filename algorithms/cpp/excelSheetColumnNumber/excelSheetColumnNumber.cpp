// Source : https://leetcode.com/problems/excel-sheet-column-number/
// Author : Zhonghuan Gao
// Date   : 2019-10-30

/********************************************************************************** 
*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701
*               
***********************************************************************************/

/**
 * 题意：
 * 求 excel 表字符列号对应的数字列号
 */
class Solution {
public:
    /**
     * 解法一：
     */
    int titleToNumber(string s) {
        int n = s.size(), res = 0;
        for (int i = n; i >= 1; i--) {
            res += (s[i - 1] - 64) * pow(26, n - i);
        }
        return res;
    }
};
