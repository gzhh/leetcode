// Source : https://leetcode.com/problems/valid-palindrome-ii/
// Author : Zhonghuan Gao
// Date   : 2019-10-13

/********************************************************************************** 
*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
Accepted
*               
***********************************************************************************/

/**
 * 题意：给你一个字符串，你最多可以从字符串中删除一个字符，使这个字符串成为一个回文串
 */
class Solution {
public:
    /**
     * 解法一：
     * 1.头往后、尾往前开始遍历字符串，判断字符是否相等
     * 2.当不想等时，跳过前面或后面的一个字符，接下去继续判断向后和向前方向的字符是否相等，
     * 直到两个字符的位置相交；最后判断两个字符的位置是否相交，若相交，则满足条件，若不相
     * 交，则不满足条件
     * 3.若直到两个字符的位置相交还没有不想等的字符，那么字符串本身就是回文串
     */
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                int i1 = i, i2 = i + 1, j1 = j, j2 = j - 1;
                while (i1 < j2 && s[i1] == s[j2]) i1++, j2--;
                while (i2 < j1 && s[i2] == s[j1]) i2++, j1--;
                return i1 >= j2 || i2 >= j1;
            }
        }
        return true;
    }
};
