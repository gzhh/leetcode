// Source : https://leetcode.com/problems/remove-element/description/
// Author : Zhonghuan Gao
// Date   : 2018-02-01

/**********************************************************************************
**

Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

**
**********************************************************************************/


/*
 * 题意：给你一个数字数组和一个数字，去掉数组里面和该数字相同的数字，返回数组中余下数，余下的数顺序可以打乱
 * 思路：记下交换的位置，若交换了，停一步，再次往后遍历
 * 例子：Given nums = [3,2,2,3], val = 3
 * 过程：[3,2,2,3] => [2,3,2,3] => [2,2,3,3]
 * 结果：[2,2]
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int res = len;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val) res--;
        }
        int tmp = 0;
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] == val && nums[i+1] != val) {
                swap(nums[tmp], nums[i+1]);
                tmp++;
                i--; // 停在当前位置
            }
            if (tmp == res) break;
        }
        return res;
    }
};


/*
更简洁一点的代码
思路：从头开始遍历，找到一个不等于 val 的元素就把它赋值给位置为 pos 的元素，每赋值一次，pos + 1
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == val) {
                continue;
            } else {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};
