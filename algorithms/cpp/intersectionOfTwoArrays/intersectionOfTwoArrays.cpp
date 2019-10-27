// Source : https://leetcode.com/problems/intersection-of-two-arrays/
// Author : Zhonghuan Gao
// Date   : 2019-10-27

/********************************************************************************** 
*
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
Each element in the result must be unique.
The result can be in any order.
*               
***********************************************************************************/

/**
 * 题意：
 * 求两个整数数组的交集
 */
class Solution {
public:
    /**
     * 解法一：
     * 利用 set 的特性来解题
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end()), res;
        for (int n : nums2) {
            if (s.count(n)) res.insert(n);
        }
        return vector<int>(res.begin(), res.end());
    }

    /**
     * 解法一优化
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s(nums1.begin(), nums1.end());
        for (int n : nums2) {
            if (s.erase(n)) res.push_back(n);
        }
        return res;
    }
};
