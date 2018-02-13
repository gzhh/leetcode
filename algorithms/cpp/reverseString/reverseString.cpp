// Source : https://leetcode.com/problems/reverse-string/
// Author : Zhonghuan Gao
// Date   : 2018-02-13

/**********************************************************************************
*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*
**********************************************************************************/

class Solution {
/*
题意：反转字符串
思路：首尾交换
*/
public:
    string reverseString(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            swap(s[i], s[len-i-1]);
        }
        return s;
    }
};
