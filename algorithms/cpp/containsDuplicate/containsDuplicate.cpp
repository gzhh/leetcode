// Source : https://leetcode.com/problems/contains-duplicate/
// Author : Zhonghuan Gao
// Date   : 2019-10-16

/********************************************************************************** 
*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*               
***********************************************************************************/

/**
 * 题意：给你一个整数数组，判断其中是否有重复的数
 */
class Solution {
public:
    /**
     * 解法一：
     * 将去重前的数组长度与去重后的数组数组长度相比
     */
    bool containsDuplicate(vector<int>& nums) {
        int n1 = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        int n2 = nums.size();
        return n1 != n2;
    }

    /**
     * 解法二：
     * 排序，比较相邻数字是否相等
     */

    /**
     * 解法三：
     * 哈希表，遍历数组，如果在哈希表中，返回 false，如果不在哈希表中，加入
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) return true;
            m[nums[i]]++;
        }
        return false;
    }
};
