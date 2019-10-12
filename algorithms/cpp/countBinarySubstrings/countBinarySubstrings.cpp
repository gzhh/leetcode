// Source : https://leetcode.com/problems/count-binary-substrings/
// Author : Zhonghuan Gao
// Date   : 2019-10-12

/********************************************************************************** 
*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

Note:
s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个只包含0和1字符的01串，统计具有相同0和1的个数，且0和1各自都是连续的子字符串的个数(即0和1不能交替出现)
 */
class Solution {
public:
    /**
     * 解法一：
     * 先计算相同字符群组的个数，然后依次比较相邻的两个字符群组中字符的个数，取较小的，全部加起来即是最后要求的数
     */
    int countBinarySubstrings(string s) {
        int cnt = 1;
        vector<int> v;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                cnt++;
            } else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        int res = 0;
        for (int i = 1; i< v.size(); i++) {
            res += min(v[i], v[i-1]);
        }
        return res;
    }

    /**
     * 解法二：
     * 解法一的优化
     */
    int countBinarySubstrings(string s) {
        int pre = 0, cur = 1, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
};
