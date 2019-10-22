// Source : https://leetcode.com/problems/fair-candy-swap/
// Author : Zhonghuan Gao
// Date   : 2019-10-22

/********************************************************************************** 
*
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.
Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.
If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

Example 1:
Input: A = [1,1], B = [2,2]
Output: [1,2]

Example 2:
Input: A = [1,2], B = [2,3]
Output: [1,2]

Example 3:
Input: A = [2], B = [1,3]
Output: [2,3]

Example 4:
Input: A = [1,2,5], B = [2,4]
Output: [5,4]

Note:
1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.
It is guaranteed there exists an answer.
*               
***********************************************************************************/

/**
 * 题意：
 * 给你两个整数数组，你只能交换两个数组中的一个数字，交换后使两个数组的和相等，
 * 找出这两个数
 */
class Solution {
public:
    /**
     * 解法一：
     * 先分别求两个数组的和，然后使A数组中的每个数和B数组中的每个数交换，
     * 当 asum - A[i] + B[j] == bsum - B[j] + A[i] 相等时，当前两个数即为所求的
     */ 
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int asum = accumulate(A.begin(), A.end(), 0), bsum = accumulate(B.begin(), B.end(), 0);
        int sum = asum + bsum;
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (asum - A[i] + B[j] == bsum - B[j] + A[i]) {
                    res.push_back(A[i]);
                    res.push_back(B[j]);
                    return res;
                }
            }
        }
        return res;
    }

    /**
     * 解法二：
     * 利用哈希表，与解法一核心算法一样 asum - A[i] + B[j] == bsum - B[j] + A[i]
     */
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> st(A.begin(), A.end());
        for (int num : B) {
            if (st.count(num + diff)) return {num + diff, num};
        }
        return {};
    }
};
