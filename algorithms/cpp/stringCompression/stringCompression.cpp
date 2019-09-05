// Source : https://leetcode.com/problems/number-of-segments-in-a-string/
// Author : Zhonghuan Gao
// Date   : 2019-09-05

/********************************************************************************** 
*
Given an array of characters, compress it in-place.
The length after compression must always be smaller than or equal to the original array.
Every element of the array should be a character (not int) of length 1.
After you are done modifying the input array in-place, return the new length of the array.
 
Follow up:
Could you solve it using only O(1) extra space?
 
Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 

Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
 

Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
 

Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*               
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一(貌似有点小问题)
     */
    int compress(vector<char>& chars) {
        int cnt = 1, pos = 0;
        string cntstr;
        for (int i = 0, len = chars.size(); i < len; i++) {
            if (i == len - 1 || chars[i] != chars[i+1]) {
                chars[pos++] = chars[i];
                cntstr = itoa(cnt);
                if (cnt > 1) {
                    for (int j = cntstr.size() - 1; j >= 0; j--)
                        chars[pos++] = cntstr[j];
                }
                cnt = 1;
            } else {
                cnt++;
                continue;
            }
        }
        chars.resize(pos);
        return pos;
    }
    
    char* itoa(int num) {
        static char ret[1000];
        int i = 0;
        while (num) {
            ret[i++] = num % 10 + '0';
            num /= 10;
        }
        return ret;
    }
    
    /**
     * 解法二
     */
    int compress(vector<char>& chars) {
        int n = chars.size(), cur = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && chars[j] == chars[i]) j++;
            chars[cur++] = chars[i];
            if (j - i == 1) continue;
            for (char c : to_string(j - i)) chars[cur++] = c;
        }
        return cur;
    }
};
