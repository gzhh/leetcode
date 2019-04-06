// Source : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Author : Zhonghuan Gao
// Date   : 2019-04-06

/********************************************************************************** 
*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*
**********************************************************************************/

class Solution {
public:
    /**
     * 思路：把所有出现过的num对应的nums[num-1]修改为负数
     * 那么新的nums中所有正数的num的index-1即为要求的
     * 4 3 2 7 8 2 3 1
     * -4 -3 -2 -7 8 2 -3 -1
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums) {
            num = abs(num);
            if (nums[num - 1] > 0) nums[num - 1] *= -1;
        }

        int len = nums.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};
