// Source : https://leetcode.com/problems/reshape-the-matrix/
// Author : Zhonghuan Gao
// Date   : 2019-04-07

/********************************************************************************** 
** 
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 思路：直接遍历原矩阵中的所有元素，同时计数，并将当前元素插入新的二维矩阵。
     * 每当新的矩阵内部行满时，换新行
     */
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if (r * c != row * col)
            return nums;
        else {
            vector<vector<int>> newNums(r);
            int k = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    newNums[k / c].push_back(nums[i][j]);
                    k++;                                                                             
                }
            }
            return newNums;
        }
    }
};
