// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : Zhonghuan Gao
// Date   : 2020-01-04

/********************************************************************************** 
*
Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*               
***********************************************************************************/

/**
 * 题意：
 * 实现函数库中的atoi函数，即将字符串转为数字
 */
class Solution {
public:
    /**
     * 解法一：
     * 1.若字符串开头是空格，则跳过开头的所有空格字符，到第一个非空格字符
     * 2.若第一个非空格字符是+或-符合，则标记sign的，若第一个非空格字符是数字，则sign默认即可，若是其他字符则直接返回0
     * 3.字符串继续向后遍历，若下一个字符是数字，则转为整型存下来，若不是数字，则返回当前的结果
     * 4.判断最后得出的数是否越界
     * 5.特殊情况 +-1 和 -+1 都不被认为是 -1
     */
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int wflag = 1, sflag = 1, sign = 1;
        long long res = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ' && wflag == 1) {
                continue;
            }
            wflag = 0;

            if ((str[i] == '+' || str[i] == '-') && sflag == 1) {
                sign = (str[i] == '+' ? sign : sign * -1);
                sflag = 0;
                continue;
            }
            sflag = 0;

            if (str[i] - '0' < 0 || str[i] - '0' > 9) return int(res) * sign;

            if (res * 10 + (str[i] - '0') > INT_MAX)
                return sign == 1 ? INT_MAX: INT_MIN;

            res = res * 10 + (str[i] - '0');
        }
        return int(res) * sign;
    }
};
