// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Zhonghuan Gao
// Date   : 2020-01-05

/********************************************************************************** 
*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*               
***********************************************************************************/

/**
 * 题意：
 * 求一个字符串中的最大回文串
 */
class Solution {
public:

    bool isPalindrom(string str) {
        int len = str.size();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
    /**
     * 解法一：超时
     * 比较暴力的方法，求出所有的子串，判断他们是否是回文串，并返回其中长度最大的回文串
     */
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string str, res;
        int len = s.size(), tmplen, maxPalindromCnt = 0;
        for (int i = 0; i < len; i++) {
            tmplen = 1;
            while (tmplen <= len - i) {
                str = s.substr(i, tmplen++);
                if (isPalindrom(str)) {
                     if (str.size() > maxPalindromCnt) {
                        maxPalindromCnt = str.size();
                        res = str;
                    }
                }
            }
        }
        return res;
    }


    /**
     * 解法二：
     * 参考：https://www.cnblogs.com/grandyang/p/4464476.html
     */
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int len = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < len;) {
            if (len - i <= maxLen / 2) break;
            int left = i, right = i;
            while (right < len - 1 && s[right + 1] == s[right]) ++right;
            i = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right; --left;
            }
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};
