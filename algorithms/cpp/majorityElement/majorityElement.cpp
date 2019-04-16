// Source : https://leetcode.com/problems/majority-element/
// Author : Zhonghuan Gao
// Date   : 2019-04-16

/********************************************************************************** 
* 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路：使用无序map来当做桶，计算每个元素出现的个数
     */
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> bucket;
        for (int num : nums) {
            if (++bucket[num] > n / 2) {
                return num;
            }
        }
        return 0;
    }

    /**
     * 思路：当cnt等于0时，给res赋新的值，即当前元素；当前元素若与res相等cnt+1；若与res不等cnt-1；
     * 不管怎样，最后一个元素肯定是Majority元素
     * 评论区答案，线性时间复杂度
     */
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 1, res = nums[0];
        for (int i = 1; i < n; i++) {
            if (cnt == 0) {
                cnt++;
                res = nums[i];
            } else if (nums[i] == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return res;
    }
};
