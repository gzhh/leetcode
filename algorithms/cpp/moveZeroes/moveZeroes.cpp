// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Zhonghuan Gao
// Date   : 2018-01-25

/********************************************************************************** 
 * * 

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

 *               
 ***********************************************************************************/



/*
 * 思路：按顺序遍历数组，若当前数不为0，则将当前数赋值给位置为pos的那个，
 * pos初始值为0，每次赋值后+1，
 * 数组遍历完后，将pos位置后面的数全部赋值为0
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];
                pos++;
            }
        }
        for (int i = pos; i < len; i++)
            nums[i] = 0;
    }
};
