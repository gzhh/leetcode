// Source : https://leetcode.com/problems/pascals-triangle-ii/
// Author : Zhonghuan Gao
// Date   : 2019-04-01

/********************************************************************************** 
** 
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

Example:
Input: 3
Output: [1,3,3,1]

Follow up:
Could you optimize your algorithm to use only O(k) extra space?
** 
***********************************************************************************/


/**
 * 思路: 杨辉三角 
 */
class Solution {
public:
    /**
     * 第一种解法: 二维数组求所有
     */
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> r(rowIndex + 1);

        for (int i = 0; i < rowIndex + 1; i++) {
            // 调整内部数组的大小
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++) {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }
        return r[rowIndex];
    }

    /**
     * 第二种解法: 一维数组求当前
     */
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1, 0);
        v[0] = 1;
        for (int i = 1; i < rowIndex + 1; i++) {
            for (int j = i; j >= 1; j--) {
                v[j] += v[j - 1];
            }
        }
        return v;
    } 
};
