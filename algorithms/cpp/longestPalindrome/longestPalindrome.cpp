// Source : https://leetcode.com/problems/longest-palindrome/
// Author : Zhonghuan Gao
// Date   : 2019-04-30

/********************************************************************************** 
**
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一：哈希表
     * 先将所有字符出现的次数写入哈希表，然后遍历哈希表，依次加上所有字符大于或等于2的偶数次数，
     * 最后字符串长度大于当前累加次数，则长度加1
     */
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (auto c : s) {
            ++m[c];
        }
        
        int sum = 0;
        for(auto &v : m)
            sum += m[v.first] - m[v.first] % 2;
        return s.size() > sum ? sum + 1 : sum;
    }
};
