// Source : https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author : Zhonghuan Gao
// Date   : 2019-10-10

/********************************************************************************** 
*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*               
**********************************************************************************/

/**
 * 题意：反转一个句子中的每个单词
 */
class Solution {
public:
    /**
     * 解法一：直接计算出每个单词的起始位置，然后使用 reverse 进行单词反转
     */
    string reverseWords(string s) {
        int pos = 0, len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + pos, s.begin() + i);
                pos = i + 1;
            }
        }
        reverse(s.begin() + pos, s.begin() + len);
        return s;
    }
}
