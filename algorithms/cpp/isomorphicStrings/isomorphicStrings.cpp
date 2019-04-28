// Source : https://leetcode.com/problems/isomorphic-strings/
// Author : Zhonghuan Gao
// Date   : 2019-04-28

/********************************************************************************** 
*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*               
***********************************************************************************/

/**
 * 题意：
 * 求同构字符串，就是说原字符串中的每个字符可由另外一个字符替代，可以被其本身替代，
 * 相同的字符一定要被同一个字符替代，且一个字符不能被多个字符替代，即不能出现一对多的映射。
 */
class Solution {
public:
    /**
     *
     * 解法一：
     * 根据一对一映射的特点，我们需要用两个哈希表分别来记录原字符串和目标字符串中字符出现情况，
     * 由于ASCII码只有256个字符，所以我们可以用一个256大小的数组来代替哈希表，并初始化为0，
     * 我们遍历原字符串，分别从源字符串和目标字符串取出一个字符，然后分别在两个哈希表中查找其值，
     * 若不相等，则返回false，若相等，将其值更新为i + 1，因为默认的值是0，所以我们更新值为i + 1，
     * 这样当 i=0 时，则映射为1，如果不加1的话，那么就无法区分是否更新了。
     */
    bool isIsomorphic(string s, string t) {
        int h1[256] = {0}, h2[256] = {0}, n = s.size();
        for (int i = 0; i < n; i++) {
            if (h1[s[i]] != h2[t[i]]) return false;
            h1[s[i]] = i + 1;
            h2[t[i]] = i + 1;
        }
        return true;
    }
};
