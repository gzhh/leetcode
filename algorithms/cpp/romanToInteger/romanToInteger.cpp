// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Zhonghuan Gao
// Date   : 2017-12-03

/********************************************************************************** 
 * * 

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

 *               
 ***********************************************************************************/


class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int current;
        int next = singleRomanNumToInt(s[len - 1]);
        int result = next;
	// 字符串从后向前遍历，若当前位置小于后面则减掉当前位置，反之则加
        for (int i = len - 2; i >= 0; i--) {
            current = singleRomanNumToInt(s[i]);
            if (current < next) {
                result -= current;
            } else {
                result += current;
            }
            next = current;
        }
        return result;
    }
    int singleRomanNumToInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

