// Source : https://leetcode.com/problems/word-pattern/
// Author : Zhonghuan Gao
// Date   : 2019-04-29

/********************************************************************************** 
*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 解法一：哈希表
     * 用两个HashMap来解答，分别将字符和单词都映射到当前的位置加1，注意这里需要加1就是为了避免默认映射值0，
     * 因为C++中的HashMap的机制是若访问一个不存在的key值，会默认建立一个映射值为0的映射。
     * 那么我们在遇到新字符和单词时，首先看 i 是否已经是 n 了，
     * 若相等了，说明此时pattern中的字符已经用完了，而str中还有多余的单词，这样是无法建立一对一映射的，直接返回false。
     * 还有当两个HashMap的映射值不相同时也返回false，否则我们同时建立单词和pattern字符和当前位置加1之间的映射，
     * 循环推出后还是要检测 i 是否和 n 相等
     */
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || m1[pattern[i]] != m2[word])
                return false;
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n;
    }
};
