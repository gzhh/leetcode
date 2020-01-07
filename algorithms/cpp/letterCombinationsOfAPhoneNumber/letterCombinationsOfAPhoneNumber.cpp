// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Zhonghuan Gao
// Date   : 2020-01-07

/********************************************************************************** 
*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*               
***********************************************************************************/

/**
 * 题意：
 *
 */
class Solution {
public:
    void letterDfs(string digits, vector<string> dict, int level, string out, vector<string> &res) {
        if (level == digits.size()) {
            res.push_back(out);
            return;
        }
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); i++) {
            letterDfs(digits, dict, level + 1, out + str[i], res);
        }
    }

    /**
     * 解法一：
     * 递归
     */
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        letterDfs(digits, dict, 0, "", res);
        return res;
    }
};
