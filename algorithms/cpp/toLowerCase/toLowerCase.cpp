// Source : https://leetcode.com/problems/to-lower-case/
// Author : Zhonghuan Gao
// Date   : 2019-10-12

/********************************************************************************** 
*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:
Input: "Hello"
Output: "hello"

Example 2:
Input: "here"
Output: "here"

Example 3:
Input: "LOVELY"
Output: "lovely"
*               
***********************************************************************************/

/**
 * 题意：
 * 将一个字符串中的大写字符转为小写字符
 */
class Solution {
public:
    /**
     * 解法一：
     * 逐个字符判断
     */
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 65 && str[i] <= 90) str[i] += 32;
        }
        return str;
    }

    /**
     * 解法二：
     * 调用库函数
     */
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};
