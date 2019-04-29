// Source : https://leetcode.com/problems/first-unique-character-in-a-string/
// Author : Zhonghuan Gao
// Date   : 2019-04-29

/********************************************************************************** 
*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 解法一：
     * 用hash表统计每个字符出现的次数，然后从头重新遍历一次，找出第一个出现一次的字符位置
     */
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        for (int i = 0, n = s.size(); i < n; i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};
