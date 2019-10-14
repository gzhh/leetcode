// Source : https://leetcode.com/problems/rotated-digits/
// Author : Zhonghuan Gao
// Date   : 2019-10-14

/********************************************************************************** 
*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Note:
N  will be in range [1, 10000].
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个正整数，判断它是否一个“好数”。题目中好数的定义是0、1、8翻转后是它本身，
 * 2和5，6和9可以互相翻转，其他剩余的数3、4、7则不符合条件，即数字中只要有3、4、7，
 * 那么这个数就不是“好数”，而0、1、8翻转后不变，故好数不能全是0、1、8组成的。
 */
class Solution {
public:
    /**
     * 解法一：
     * 将数字转化为字符串，依次检查每个字符是否满足条件
     */
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++) {
            if (check(i)) res++;
        }
        return res;
    }
    bool check(int N) {
        string s = to_string(N);
        bool flag = false;
        for (char c : s) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;
        }
        return flag;
    }
};
