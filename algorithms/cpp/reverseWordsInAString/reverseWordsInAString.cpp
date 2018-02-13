// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : Zhonghuan Gao
// Date   : 2018-02-13

/**********************************************************************************
*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*
**********************************************************************************/

class Solution {
/*
题意：按单词反转
思路：先反转整个字符串，再反转每个单词
*/
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int len = s.length();
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + pos, s.begin() + i);
                pos = i + 1;
            }
        }
        reverse(s.begin() + pos, s.end());
    }
};
