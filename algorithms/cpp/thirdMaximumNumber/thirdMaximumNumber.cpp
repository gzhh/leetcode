// Source : https://leetcode.com/problems/third-maximum-number/
// Author : Zhonghuan Gao
// Date   : 2019-04-06

/********************************************************************************** 
*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 思路: 利用stl set去重并默认排序的特性
     */
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
            if (s.size() > 3) s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
