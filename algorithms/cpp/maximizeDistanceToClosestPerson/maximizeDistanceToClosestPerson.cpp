// Source : https://leetcode.com/problems/maximize-distance-to-closest-person
// Author : Zhonghuan Gao
// Date   : 2019-04-11

/********************************************************************************** 
**
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 思路：每个点都往左往右找最近的1，得到left_i, right_i,
     * 当前点的离最近1的距离即为min(left_i, right_i)
     */
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), res = 0;
        int left = 0, right = 0, j, k;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                left = 0;
                right = 0;
            } else {
                j = i;
                k = i;
                while (j >= 0) {
                    if (seats[j] == 1) {
                        left = i - j;
                        break;
                    }
                    if (j == 0) {
                        left = n - 1;
                        break;
                    }
                    j--;
                }       
                while (k < n) {
                    if (seats[k] == 1) {
                        right = k - i;
                        break;                        
                    }
                    if (k == n - 1) {                                                                
                        right = n - 1;
                        break;
                    }
                    k++; 
                }
            }
            res = max(res, min(left, right));
        }
        return res;
    }

    /**
     * 评论区答案:
     * Count the numbers of continuous zeros in the prefix, res = max(res, zeros)
     * Count the numbers of continuous zeros in middle, res = max(res, (zeros + 1) / 2)
     * Count the numbers of continuous zeros in the suffix, res = max(res, zeros)
     */
    int maxDistToClosest(vector<int>& seats) {
        int i, j, res = 0, n = seats.size();
        for (i = j = 0; j < n; j++)
            if (seats[j] == 1) {
                res = i > 0 ? max(res, (j - i + 1) / 2) : j;
                i = j + 1;
            }
        res = max(res, n - i);
        return res;
    }
};

