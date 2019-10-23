// Source : https://leetcode.com/problems//sort-array-by-parity/
// Author : Zhonghuan Gao
// Date   : 2019-10-23

/********************************************************************************** 
*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.

Example 1:
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:
1 <= A.length <= 5000
0 <= A[i] <= 5000
Accepted
*               
***********************************************************************************/

/**
 * 题意：
 * 给你一个非负整数数组，将其中的偶数和奇数分隔开，偶数在前部分，奇数在后部分
 */
class Solution {
public:
    /**
     * 解法一：
     * 先遍历一遍数组，将偶数和奇数分别存进两个新数组，然后遍历奇数数组，将所有元素都加到偶数数组末尾
     */
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res, odd;
        for (int num : A) {
            if (num % 2 == 0) res.push_back(num);
            else odd.push_back(num);
        }
        for (int num : odd)
            res.push_back(num);
        return res;
    }

    /**
     * 解法二：
     * 不实用额外空间
     */
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = 0; j < A.size(); ++j) {
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        }
        return A;
    }
};
