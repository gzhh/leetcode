// Source : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Author : Zhonghuan Gao
// Date   : 2019-05-11

/********************************************************************************** 
*
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)
Return the largest possible sum of the array after modifying it in this way.

Example 1:
Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].

Example 2:
Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].

Example 3:
Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
 
Note:
1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 解法一：
     * 思路：先从小到大排序，然后统计数组中小于0的元素的个数 negativeCount
     * 判断当 negativeCount >= K，则直接按顺序将前 K 个数取绝对值，
     * 当 negativeCount < k，则先将 前 negativeCount 个数取绝对值，
     * 然后判断第 negativeCount 和第 negativeCount + 1 两个数的绝对值哪个大，
     * 取较小的那个元素乘以 (K - negativeCount) % 2 == 0 ? 1 : -1
     */
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int negativeCount = 0;
        for (auto i : A) {
            if (i >= 0) break;
            negativeCount++;
        }
        if (negativeCount >= K) {
            for (int i = 0; i < K; i++)
                A[i] = -A[i];
        } else {
            for (int i = 0; i < negativeCount; i++)
                A[i] = -A[i];
            if (negativeCount > 0 && abs(A[negativeCount - 1]) < abs(A[negativeCount])) {
                A[negativeCount - 1] *= ((K - negativeCount) % 2 == 0 ? 1 : -1);
            } else {
                A[negativeCount] *= ((K - negativeCount) % 2 == 0 ? 1 : -1);
            }
        }
        int res = 0;
        for (auto i : A)
            res += i;
        return res;
    } 
};
