// Source : https://leetcode.com/problems/transpose-matrix/
// Author : Zhonghuan Gao
// Date   : 2019-10-22

/********************************************************************************** 
*
Given a matrix A, return the transpose of A.
The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:
Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 
Note:
1 <= A.length <= 1000
1 <= A[0].length <= 1000
*               
***********************************************************************************/

/**
 * 题意：
 * 将矩阵翻转
 */
class Solution {
public:
    /**
     * 解法一：
     */
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};
