// Source : https://leetcode.com/problems/positions-of-large-groups/
// Author : Zhonghuan Gao
// Date   : 2019-04-10

/********************************************************************************** 
** 
In a string S of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
The final answer should be in lexicographic order.

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]

Note:  1 <= S.length <= 1000
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 思路: 每个组数量大于等于3，则将start,end插入数组
     */
    vector<vector<int>> largeGroupPositions(string S) {
        int n = S.length();
        vector<vector<int>> res(n);
        int j = 0, cnt = 1, start = 0;
        for (int i = 1; i < n; i++) {
            if (S[i-1] == S[i]) {
                cnt++;
                continue;
            } else {
                if (cnt >= 3) {
                    res[j].push_back(start);
                    res[j].push_back(i-1);
                    j++;
                }
                cnt = 1;
                start = i;
            }
        }
        if (cnt >= 3) {
            res[j].push_back(start);
            res[j].push_back(n - 1);
            j++;
        }
        res.resize(j);
        return res;
    }

    /**
     * 评论区答案
     * For every groups, find its start index i and end index j - 1
     * Group length is j - i, if it's no less than 3, add (i, j) to result.
     */
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < S.size(); i = j) {
            while (j < S.size() && S[j] == S[i]) ++j;
            if (j - i >= 3)
                res.push_back({i, j - 1});
        }
        return res;
    }
};
