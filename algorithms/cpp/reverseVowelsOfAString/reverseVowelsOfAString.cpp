// Source : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author : Zhonghuan Gao
// Date   : 2019-07-31

/**********************************************************************************
*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*
**********************************************************************************/

class Solution {
/*
题意：反转一个字符串中的元音字母
*/
public:
    /**
     * 解法一
     */
    string reverseVowels(string s) {
        char str[] = "aeiouAEIOU";
        stack<char> vowels;
        
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (strchr(str, s[i]) != NULL) {
                vowels.push(s[i]);
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (strchr(str, s[i]) != NULL) {
                s[i] = vowels.top();
                vowels.pop();
            }
        }
        return s;
    }

    /**
     * 解法二
     */
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string t = "aeiouAEIOU";
        while (left < right) {
            if (t.find(s[left]) == string::npos) ++left;
            else if (t.find(s[right]) == string::npos) --right;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};
