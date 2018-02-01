// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Author : Zhonghuan Gao
// Date   : 2018-02-01

/**********************************************************************************
**

Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

**
**********************************************************************************/



class Solution {
  /*
  题意：从一个有序数组中删除重复的元素，并返回修改后数组的长度。
  思路：
  1.记录第一个相同的元素位置 pos（初始为 0），记录当前不重复元素的个数 res（初始为 1）
  2.遍历数组，找到第二个相同元素的位置 i，把当前位置元素的值赋值给位置为 res 的元素，
  修改 pos 为当前位置 i，并且让 res 的位置向后移动一位
  3.重复 1、2 两步
  */
  public:
      int removeDuplicates(vector<int>& nums) {
          int len = nums.size();
          if (len == 0) return 0;

          int pos = 0; // 数组中每个相同元素的第一个元素的位置，且不断变化
          int res = 1; // 当前不重复元素的个数，且不断变化
          for (int i = 1; i < len; i++) {
              if (nums[i] == nums[pos]) {
                  continue;
              }
              else {
                  pos = i;
                  nums[res++] = nums[i];
              }
          }

          return res;
      }
  };
