// Source : https://leetcode.com/problems/container-with-most-water/
// Author : Zhonghuan Gao
// Date   : 2019-04-13

/********************************************************************************** 
*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 暴力法
     */
    int maxArea(vector<int>& height) {
        int n = height.size(), res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                res = max(res, min(height[i], height[j]) * (j - i));
        return res;
    }

    /**
     * Two Pointer Approach
     */
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j) {
            res = max(res, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
