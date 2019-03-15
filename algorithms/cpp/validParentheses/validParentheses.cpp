// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Zhonghuan Gao
// Date   : 2019-03-15

/**********************************************************************************
*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*
**********************************************************************************/
class Solution {
/**
 * 思路: 使用栈原理。遍历字符串，当是左括号时入栈，
 * 若是与栈顶对应的右括号则出栈，最后若栈为空则为true。
 */ 
public:
    // 解法1
    bool isValid(string s) {
        int len = s.length();
        stack<char> bucket;

        if (len > 0) {
            bucket.push(s[0]);
        }
        for (int i = 1; i < len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                bucket.push(s[i]);  
            } else {
                if (bucket.empty()) return false;
                if (s[i] == ')') {
                    if (bucket.top() == '(') bucket.pop();
                    else return false;
                } else if (s[i] == '}') {
                    if (bucket.top() == '{') bucket.pop();
                    else return false;
                } else {
                    if (bucket.top() == '[') bucket.pop();
                    else return false;
                }
            }
        }
        if (bucket.empty()) return true; 
        return false;;
    }

    // 解法1优化
    bool isValid(string s) {
        stack<char> bucket;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                bucket.push(c);
            } else {
                if (bucket.empty()) return false;
                if (c == ')' && bucket.top() != '(') return false;
                if (c == '}' && bucket.top() != '{') return false;
                if (c == ']' && bucket.top() != '[') return false;
                bucket.pop();
            }
        }
        return bucket.empty();
    }
};
