// Source : https://leetcode.com/problems/add-strings/
// Author : Zhonghuan Gao
// Date   : 2019-08-06

/********************************************************************************** 
*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*               
**********************************************************************************/

/**
 * 题意：两个数字字符串相加
 */
class Solution {
public:
    /**
     * 解法一：
     * 考虑进位、补位
     */
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        int a, b, sum;
        while (i >= 0 || j >= 0) {
            a = i >= 0 ? num1[i--] - '0' : 0;
            b = j >= 0 ? num2[j--] - '0' : 0;
            sum = a + b + carry;
            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry ? "1" + res : res;
    }
};
