// Source : https://leetcode.com/problems/non-decreasing-array/
// Author : Zhonghuan Gao
// Date   : 2019-10-18

/********************************************************************************** 
*
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.

Note: The n belongs to [1, 10,000].
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个整数数组，你最多有一次机会改数组中的一个数，是数组的元素满足递增（可以等于）
 */
class Solution {
public:
    /*
    两种情况：当比换前面一个，换后面一个
    */
    /**
     * 解法一：
     * 遍历数组，第一次碰到当前元素小于前一个原素时，有两种修改情况，
     * 既可以修改当前元素，也可以修改前一个元素，经过列举例子，我们发现规则
     * 3. 2 4
     * 1 3. 2 4
     * 2 3 3 2. 4
     * 1.当前元素小于往前第二个元素时，则修改当前元素
     * 2.当前元素大于往前第二个元素时，则修改前一个元素
     * 继续往后遍历，若再出现当前元素小于前一个元素时，则直接返回false，否则最后返回true
     */
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size(), cnt = 0;
        if (len == 1) return true;
        for (int i = 1; i < len; i++) {
            if (i - 2 < 0) {
                if (nums[i-1] > nums[i]) {
                    nums[i-1] = nums[i];
                    cnt++;
                }
            } else {
                if (nums[i-1] > nums[i]) {
                    if (nums[i-2] > nums[i]) {
                        nums[i] = nums[i-1];
                    } else {
                        nums[i-1] = nums[i];
                    }
                    cnt++;
                }
            }
            if (cnt > 1) return false;
        }
        return true;
    }

    /**
     * 解法一的优化
     */
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (cnt == 0) return false;
                if (i == 1 || nums[i] >= nums[i - 2]) nums[i - 1] = nums[i];
                else nums[i] = nums[i - 1];
                --cnt;
            } 
        }
        return true;
    }
};
