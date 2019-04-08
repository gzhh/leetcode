// Source : https://leetcode.com/problems/maximum-average-subarray-i/
// Author : Zhonghuan Gao
// Date   : 2019-04-08

/**********************************************************************************
*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*
**********************************************************************************/

class Solution {
public:
    /**
     * 思路：从0-k，依次求sum[i]+sum[i+1]+...+sum[i+k]，每次选较大的sum和
     * 但是双重循环，结果超时了
     */
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), max = INT_MIN, tmp;
        for (int i = 0; i <= n - k; i++) {
            tmp = 0;
            for (int j = i; j < i + k; j++) {
                tmp += nums[j];
            }
            if (tmp > max) max = tmp; 
        }
        return (double)max / k;
    }

    /**
     * 思路: 在一个循环内求
     */
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MIN;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                sum += nums[i];
            } else {
                res = (res > sum ? res : sum);
                sum += nums[i] - nums[i-k];
            }
        }
        res = (res > sum ? res : sum);
        return double(res) / k;
    }
};
