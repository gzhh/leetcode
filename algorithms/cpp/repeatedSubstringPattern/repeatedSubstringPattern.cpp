// Source : https://leetcode.com/problems/repeated-substring-pattern/
// Author : Zhonghuan Gao
// Date   : 2019-09-16

/********************************************************************************** 
*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*               
***********************************************************************************/

/**
 * 解法一：逆向思维
 */
class Solution {
public:
    /**
     * 思路：假如原字符串是由多个相同的子字符串组成的，那么将两个原字符串相加得到的
     * 新字符串同样是可以由多个相同的子字符串组成的。这时我们可以去掉新字符串的头尾
     * 各一个字符，并在这里面找是否存在原字符串，若找到则可以证明原字符串是由多个相
     * 通的子字符串组成的。
     */
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != -1;
    }
};
