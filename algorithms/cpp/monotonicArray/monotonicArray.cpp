// Source : https://leetcode.com/problems/monotonic-array/
// Author : Zhonghuan Gao
// Date   : 2019-04-12

/********************************************************************************** 
*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路: 遍历两次，一次检查是否递增，一次检查是否递减
     */
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool isIncrease = true, isDecrease = true;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i+1]) {
                isIncrease = false;
                break;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (A[i] < A[i+1]) {
                isDecrease = false;
                break;
            }
        }
        return isIncrease || isDecrease;
    }

    /**
     * 优化
     */
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};
