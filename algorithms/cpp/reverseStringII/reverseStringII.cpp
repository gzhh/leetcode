// Source : https://leetcode.com/problems/reverse-string-ii/
// Author : Zhonghuan Gao
// Date   : 2019-10-09

/********************************************************************************** 
*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*               
**********************************************************************************/

/**
 * 题意：每隔k个字符，翻转k个字符，最后如果不够k个字符，那么剩下几个字符就翻转几个字符。
 */
class Solution {
public:
    /**
     * 解法一：更直接
     * 先算出字符串s能分成几个长度为k的子字符串，然后开始遍历这些子字符串，隔一个就翻转，
     * 最后判断是否到s的末尾，将末尾剩余字符串的也翻转。
     */
    string reverseStr(string s, int k) {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; i++) {
            if (i % 2 == 0) {
                if (i != cnt) {
                    reverse(s.begin() + i * k, s.begin() + (i + 1) * k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
        }
        return s;
    }

    /**
     * 解法二：更简洁
     * 每隔2k个字符遍历原字符串，然后翻转当前位置到当前位置加k的子字符串，
     * 最后翻转的结尾位置是i+k和末尾位置的较小值。
     */
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};
