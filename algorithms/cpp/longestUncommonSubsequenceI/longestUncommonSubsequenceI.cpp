// Source : https://leetcode.com/problems/longest-uncommon-subsequence-i/
// Author : Zhonghuan Gao
// Date   : 2019-09-19

/********************************************************************************** 
*
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"), 
because "aba" is a subsequence of "aba", 
but not a subsequence of any other strings in the group of two strings. 

Note:
Both strings' lengths will not exceed 100.
Only letters from a ~ z will appear in input strings.
*               
**********************************************************************************/

/**
 * 求两个字符串的Longest Uncommon Subsequence
 */
class Solution {
public:
    /**
     * 思路：当两个字符串不相等时，若两字符串长度相等，则Longest Uncommon Subsequence为其中
     * 任一字符串；若两字符串不相等时，则Longest Uncommon Subsequence为其中长度较大字符串。
     * 当两个字符串相等时，则没有Uncommon Subsequence
     */
    int findLUSlength(string a, string b) {
        return a != b ? max(a.size(), b.size()) : -1;
    }
};
