// Source : https://leetcode.com/problems/implement-strstr/
// Author : Zhonghuan Gao
// Date   : 2019-04-14

/********************************************************************************** 
*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 暴力法
     */
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length(), k;
        if (m == 0) return 0;
        for (int i = 0; i < n; i++) {
            k = 0;
            for (int j = i; j < n; j++) {
                if (haystack[j] == needle[k]) {
                    k++;
                    continue;
                } else {
                    if (m == k) return i;
                    else break;
                }
            }
            if (m == k) return i;
        }
        return -1;
    }

    /**
     * 暴力法优化
     */
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }

    /**
     * KMP算法最优
     */
};
