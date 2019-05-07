// Source : https://leetcode.com/problems/ransom-note/
// Author : Zhonghuan Gao
// Date   : 2019-05-07

/********************************************************************************** 
*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true 
*               
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一：哈希表
     * 先将magazine字符串按键为字符，值为字符个数存入哈希表，
     * 然后遍历ransomNote字符串，并将每次出现的字符在哈希表
     * 中对应的字符数减1，若出现当前字符数小于0，则直接返回false，否则最后返回true
     */
    bool canConstruct(string ransomNote, string magazine) {
        int lr = ransomNote.length(), lm = magazine.length();
        map<char, int> mp;
        for (int i = 0; i < lm; i++) {
            mp[magazine[i]]++;
        }
        for (int i = 0; i < lr; i++) {
            mp[ransomNote[i]]--;
            if (mp[ransomNote[i]] < 0) return false;
        }
        return true; 
    }
};
