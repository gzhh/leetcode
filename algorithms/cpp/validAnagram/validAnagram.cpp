// Source : https://leetcode.com/problems/valid-anagram/
// Author : Zhonghuan Gao
// Date   : 2018-02-26

/**********************************************************************************
*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.
*
**********************************************************************************/

class Solution {
/*
题意：判断两个字符串是否是异位构词
思路：1.排序比较两个字符串 2.字符计数法
*/
public:
	bool isAnagram(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
    
	bool isAnagram(string s, string t)
    {   
        if (s.length() != t.length()) return false;
        int len = s.length();
        int counts[26] = {0};
        for (int i = 0; i < len; i++) {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }   
        for (int i = 0; i < 26; i++)
            if (counts[i] != 0) return false;
        return true;
    } 
};
