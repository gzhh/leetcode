// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : Zhonghuan Gao
// Date   : 2018-02-03

/**********************************************************************************
**

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being
1, 1, 2, 2 and 3.It doesn't matter what you leave beyond the new length.

**
**********************************************************************************/
class Solution {
/*
题意：从一个有序数组中删除重复的元素，且只能删除总个数大于3的重复元素。
思路：遍历数组，记录从0到当前位置所能容纳符合要求的最多元素count
*/
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return len;

        int count = 2;
        for (int i = 2; i < len; i++) {
            if (nums[i] > nums[count-2]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
