// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Zhonghuan Gao
// Date   : 2019-05-08

/**********************************************************************************
*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
           Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*
*/
class Solution {
public:
    /**
     * 解法一：滑动窗口算法
     * 利用HashMap记录字符和其出现位置的映射，
     * 维护了一个滑动窗口，窗口内都是没有重复的字符，由于窗口不停向右滑动，
     * 所以只记录每个字符最后出现的位置，要求窗口的大小，我们需要一个变量
     * pos 来指向滑动窗口的左边界
     */
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int n = s.size(), res = 0, pos = -1;
        for (int i = 0; i < n; i++) {
            if (mp.count(s[i]) && mp[s[i]] > pos) {
                pos = mp[s[i]];
            }
            mp[s[i]] = i;
            res = max(res, i - pos);            
        }
        return res;
    }
};
