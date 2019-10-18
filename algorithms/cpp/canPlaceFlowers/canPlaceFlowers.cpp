// Source : https://leetcode.com/problems/can-place-flowers/
// Author : Zhonghuan Gao
// Date   : 2019-10-18

/********************************************************************************** 
*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False

Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
*               
***********************************************************************************/

/**
 * 给你一个只包含0、1的数字数组，求是否还能在0数字的位置放n个1，且要求每个1不相邻
 */
class Solution {
public:
    /**
     * 解法一：
     * 判断当前位置是否可放置的条件
     * 1.头部：数组长度为1且这一个元素为0，数组长度大于或等于2且前两个元素都为0
     * 2.中间：当前位置和当前位置的前后个一位元素都为0
     * 3.尾部：尾部的前一位和尾部元素都为0
     * 判断可放置计数后需把原位置数替换为1
     */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, len = flowerbed.size();
        if  ((len == 1 && flowerbed[0] == 0)
            || (len >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0)) {
            cnt = 1;
            flowerbed[0] = 1;
        }
        for (int i = 1; i < len; i++) {
            if (i != len - 1) {
                if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    cnt++;
                    flowerbed[i] = 1;
                }
            } else {
                if (flowerbed[i-1] == 0 && flowerbed[i] == 0) {
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
        }
        return cnt >= n;
    }
};
