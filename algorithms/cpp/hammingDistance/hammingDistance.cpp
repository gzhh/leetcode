// Source : https://leetcode.com/problems/hamming-distance/
// Author : Zhonghuan Gao
// Date   : 2019-04-16

/********************************************************************************** 
*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 题意: 求两个数之间的hamming distance
     * 思路: https://en.wikipedia.org/wiki/Hamming_distance
     * 先求两个数的异或，然后统计位数为1的个数
     */
    int hammingDistance(int x, int y) {
        int dist = 0;
        for (int val = x ^ y; val > 0; val /= 2) {
            if (val & 1)
                dist++;
        }
        return dist;
    }
};
