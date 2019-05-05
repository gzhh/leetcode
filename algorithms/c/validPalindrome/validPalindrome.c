// Source : https://leetcode.com/problems/valid-palindrome/
// Author : Zhonghuan Gao
// Date   : 2019-05-05

/********************************************************************************** 
*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*               
***********************************************************************************/

// isalnum()
int isAlphaNum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return 1;
    return 0;
}

/**
 * 思路：使用两个指针，一个指向头元素，一个指向尾元素，头指针向后移动，
 * 尾指针向前移动，跳过非alpha字符，每次忽略大小写比较前后两个字符是否相等，
 * 每次都相等则为真，否则为假
 */
int isPalindrome(char *s)
{
    int n = strlen(s);
    if (!n) return 1;

    char *p1 = s, *p2 = s + n - 1;
    while (p1 < p2) {
        if (!isAlphaNum(*p1)) { p1++; continue; }
        if (!isAlphaNum(*p2)) { p2--; continue; }
        // tolower()
        if ((*p1++ + 32 - 'a') % 32 != (*p2-- + 32 - 'a') % 32) return 0;
    }
    return 1;
}
