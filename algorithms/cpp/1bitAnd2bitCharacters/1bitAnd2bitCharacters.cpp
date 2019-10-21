// Source : https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author : Zhonghuan Gao
// Date   : 2019-10-21

/********************************************************************************** 
*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.

Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
*               
***********************************************************************************/

/**
 * 给你一个只有0和1的数组，其中数字组合有一字节的0和两字节10或11两种，且数组最后一个
 * 数字总是0，求按组合分后最后是否是0
 */
class Solution {
public:
    /**
     * 解法一：贪心法
     * 从头开始遍历，如果是0，i自增1；如果是1，i自增2。最后判断是否i等于n-1。
     */
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        while (i < n - 1) {
            // solution1
            if (bits[i] == 0) i++;
            else i += 2;
            // solution2
            // i += bits[i] + 1;
        }
        return i == n - 1;
    }
};
