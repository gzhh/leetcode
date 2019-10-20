// Source : https://leetcode.com/problems/degree-of-an-array/
// Author : Zhonghuan Gao
// Date   : 2019-10-20

/********************************************************************************** 
*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*               
***********************************************************************************/

/**
 * 题意：
 * 从数组中找出一个拥有相同 degree (这里即数字出现的最多次数)的子数组，求最小子数组的长度
 * 注意：子数组的元素必须是连续的
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        /*
         * 解法一：
         * 1.使用hash表统计得出元素出现最多的数，可能有多个，并将他们存入一个数组
         * 2.依次求出这个数组中每个数在原数组中第一次出现和最后一次出现的直接的长度
         * 3.取长度的最小值
         */
        unordered_map<int, int> m;
        int cnt = 0;
        for (int num : nums) {
            m[num]++;
            if (m[num] > cnt) cnt++;
        }
        vector<int> v;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second == cnt) v.push_back(it->first);

        int res = nums.size();
        for (int num : v) {
            int first, last;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == num) {
                    first = i;
                    break;
                }
            }
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] == num) {
                    last = i;
                    break;
                }
            }
            res = min(res, last - first + 1);
        }
        return res;
    }

    /**
     * 解法一的优化
     */
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX, degree = 0;
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (++m[nums[i]] == 1) {
                pos[nums[i]] = {i, i};
            } else {
                pos[nums[i]].second = i;
            }
            degree = max(degree, m[nums[i]]);
        }
        for (auto a : m) {
            if (degree == a.second) {
                res = min(res, pos[a.first].second - pos[a.first].first + 1);
            }
        }
        return res;
    }
};
