// Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author : Zhonghuan Gao
// Date   : 2019-05-09

/********************************************************************************** 
*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*               
***********************************************************************************/

class Solution {
public:

    /**
     * 解法一：哈希表(超时)
     * 思路：先统计字符串p中字符出现的次数，然后从s的开头开始，每次找p字符串长度个字符，
     * 来验证字符个数是否相同，如果不相同直接break，如果一直都相同了，则将起始位置加入
     * 结果res中
     */
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        int sn = s.size(), pn = p.size();
        vector<int> res;
        map<char, int> m1;
        for (int i = 0; i < pn; i++)
            m1[p[i]]++;
        for (int i = 0; i <= sn - pn; i++) {
            map<char, int> m2 = m1;
            bool flag = true;
            for (int j = i; j < i + pn; j++) {
                if (--m2[s[j]] < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }
        return res;
    }

    /**
     * 解法一优化：利用vector代替哈希表
     */
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, mp(128, 0);
        int ns = s.size(), np = p.size();

        for (char c : p) mp[c]++;
        for (int i = 0; i < ns; i++) {
            bool flag = true;
            vector<int> tmp = mp;
            for (int j = i; j < i + np; ++j) {
                if (--tmp[s[j]] < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(i);
        }
        return res;
    }
};
