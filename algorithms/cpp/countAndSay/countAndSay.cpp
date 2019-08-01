// Source : https://leetcode.com/problems/count-and-say/
// Author : Zhonghuan Gao
// Date   : 2019-08-02

/********************************************************************************** 
*
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
*               
***********************************************************************************/

/**
 * 题意：这道题的题意有点不清楚，下面这个连接里面会把题意说的更清楚一些
 * https://www.careercup.com/question?id=4425679
 */
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) {
            int len = res.size();
            string tmp = "";
            for (int i = 0; i < len; i++) {
                int count = 1, j = i + 1;
                while (j < len) {
                    if (res[i] != res[j++]) break;
                    count++;
                    i++;
                }
                tmp += to_string(count);
                tmp += res[i];
            }
            res = tmp;
        }
        return res;
    }
};
