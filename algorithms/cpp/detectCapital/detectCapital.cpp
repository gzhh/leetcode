// Source : https://leetcode.com/problems/detect-capital/
// Author : Zhonghuan Gao
// Date   : 2019-09-19

/********************************************************************************** 
*
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
1.All letters in this word are not capitals, like "leetcode".
2.Only the first letter in this word is capital, like "Google".
3.Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路一：判断大写字符的个数，符号正常字符串的表示法有
     * 1.第一个字符大写，且大写字符个数为1
     * 2.大写字符的个数为字符串的长度
     * 3.大写字符的个数为0
     */
    bool detectCapitalUse(string word) {
        bool flag = false;
        int cnt = 0, len = word.size();
        for (int i = 0; i < len; i++) {
            if (word[i] - '0' >= 17 && word[i] - '0' <= 42) {
                if (i == 0) flag = true;
                cnt++;
            }
        }
        if (cnt == 0)
            return true;
        else if (flag && (cnt == 1 || cnt == len))
            return true;
        else
            return false;
    }
};
