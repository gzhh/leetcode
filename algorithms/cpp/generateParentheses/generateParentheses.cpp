// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Zhonghuan Gao
// Date   : 2020-01-07

/********************************************************************************** 
*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*               
***********************************************************************************/

/**
 * 题意：
 * 求所有正确的括号匹配
 */
class Solution {
public:
    void genDfs(int left, int right, string str, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(str);
        else {
            if (left > 0) genDfs(left - 1, right, str + '(', res);
            if (right > 0) genDfs(left, right - 1, str + ')', res);
        }
    }

    /**
     * 解法一：
     * 递归法
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genDfs(n, n, "", res);
        return res;
    }
};
