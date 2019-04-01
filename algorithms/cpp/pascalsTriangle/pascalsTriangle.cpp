// Source : https://leetcode.com/problems/pascals-triangle/
// Author : Zhonghuan Gao
// Date   : 2019-04-01

/********************************************************************************** 
** 
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
** 
***********************************************************************************/


/**
 * 思路: 杨辉三角 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            // 调整内部数组的大小
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++) {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }
        return r;
    }
};
