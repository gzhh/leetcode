// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author : Zhonghuan Gao
// Date   : 2019-10-28

/********************************************************************************** 
*
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*               
***********************************************************************************/

/**
 * 题意：
 * 给你两个整数数组，求交集，但是相同的元素需要列出多个
 */
class Solution {
public:
    /**
     * 解法一：
     * 先将两个数组分别存入map，然后遍历map1判断其中元素是否存在于map2，列出
     * 每个相同元素的最小个数
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for (int n : nums1) m1[n]++;
        for (int n : nums2) m2[n]++;
        vector<int> res;
        for (unordered_map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
            if (m2[it->first]) {
                int tmp = min(it->second, m2[it->first]);
                while (tmp--) res.push_back(it->first);
            }
        }
        return res;
    }

    /**
     * 解法一优化：
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto a : nums1) ++m[a];
        for (auto a : nums2) {
            if (m[a]-- > 0) res.push_back(a);
        }
        return res;
    }

    /**
     * 解法二：
     * 先给两个数组排序，然后用两个指针分别指向两个数组的起始位置，如果两个指针指的数字相等，
     * 则存入结果中，两个指针均自增1，如果第一个指针指的数字大，则第二个指针自增1，反之亦然
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};
