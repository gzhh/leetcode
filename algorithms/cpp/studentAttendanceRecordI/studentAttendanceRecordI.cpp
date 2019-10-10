// Source : https://leetcode.com/problems/student-attendance-record-i/
// Author : Zhonghuan Gao
// Date   : 2019-10-10

/********************************************************************************** 
*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*               
**********************************************************************************/

/**
 * 题意：判断一个字符串中字符串 A 的数量是否超过 1，并且字符 L 是否连续超过 2 个 
 */
class Solution {
public:
    /**
     * 解法一
     */
    bool checkRecord(string s) {
        int a = 0, len = s.size();
        bool isContinue = false;
        for (int i = 0; i < len; i++) {
            if (s[i] == 'A') a++;
            else if (s[i] == 'L') {
                if (i + 2 < len && s[i+1] == 'L' && s[i+2] == 'L')
                    isContinue = true;
            }
        }
        return a <= 1 && !isContinue;
    }

    /**
     * 解法二
     */
    bool checkRecord(string s) {
        int a=0, l=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='A') a++;
            if(s[i]=='L') l++;
            else l=0;
            if(a>1||l>2) return false;
        }
        return true;
    }
}
