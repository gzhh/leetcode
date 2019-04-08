// Source : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Author : Zhonghuan Gao
// Date   : 2019-04-08

/********************************************************************************** 
*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路一:复制一个新的数组并排好序，与原数组对比
     * 找第一和最后一个不匹配的元素
     */
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != sorted[i]) break;
            l++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] != sorted[i]) break;
            r--;
        }
        if (r - l + 1 < 0) return 0;
        return r - l + 1;
    }

    /**
     * 优化思路一
     */
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == sorted[i]) {
            i++;
        }
        while (j > i && nums[j] == sorted[j]) {
            j--;
        }
        return j + 1 - i;
    }

    /**
    思路二(来自讨论区):
    max on left, min on right - O(N)
    The idea is that:

    1From the left, for a number to stay untouched, there need to be no number less than it on the right hand side;
    2.From the right, for a number to stay untouched, there need to be no number greater than it on the left hand side;
    Those 2 can be easily checked if we build 2 vectors:

    1.max so far from the left,
    2.and min so far from the right;
    */

    /**
     *            /------------\
     * nums:  [2, 6, 4, 8, 10, 9, 15]
     * minr:   2  4  4  8   9  9  15
     *         <--------------------
     * maxl:   2  6  6  8  10 10  15
     *         -------------------->
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxlhs(n);   // max number from left to cur
        vector<int> minrhs(n);   // min number from right to cur
        for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minrhs[i] = minr = min(minr, nums[i]);
        for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxlhs[i] = maxl = max(maxl, nums[i]);

        int i = 0, j = n - 1;
        while (i < n && nums[i] <= minrhs[i]) i++;
        while (j > i && nums[j] >= maxlhs[j]) j--;

        return j + 1 - i;
    }
};
