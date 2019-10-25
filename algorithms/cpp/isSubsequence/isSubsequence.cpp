// Source : https://leetcode.com/problems/is-subsequence/
// Author : Zhonghuan Gao
// Date   : 2019-10-25

/********************************************************************************** 
*
Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
*               
***********************************************************************************/

/**
 * 题意：
 * 判断是否是子序列
 */
class Solution {
public:
    /**
     * 解法一：暴力法
     * 时间复杂度O(n*n)，空间复杂度O(1)
     */
    bool isSubsequence(string s, string t) {
        int pos = 0, cnt = 0, slen = s.size(), tlen = t.size();
        if (slen == 0) return true;
        for (int i = 0; i < slen; i++) {
            for (int j = pos; j < tlen; j++) {
                if (s[i] == t[j]) {
                    pos = j + 1;
                    cnt++;
                    break;
                }
            }
            if (cnt == slen) return true;
        }
        return false;
    }

    /**
     * 解法二：
     * 解法一优化，只需要一个循环遍历字符串 t
     * 时间复杂度O(max(len(s), len(t)))，空间复杂度O(1)
     */
    bool isSubsequence(string s, string t) {
        int i, j;
        for (i = 0, j = 0; i < s.size(), j < t.size(); ) {
            if (s[i] == t[j]) i++, j++;
            else j++;
        }
        return i == s.size();
    }

    /**
     * 解法三：
     */
};
