// Source : https://leetcode.com/problems/length-of-last-word/description/
// Author : Zhonghuan Gao
// Date   : 2018-08-10

/**********************************************************************************
**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
**
**********************************************************************************/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if (len == 0) return 0;
        
        // 特殊情况: "a "
        while (s[len-1] == ' ')
            len--;
        
        int sum = 0;
		// 特殊情况: "a"
        while (s[--len] != ' ' && len >= 0)
            sum++;
        
        return sum;
    }
};
