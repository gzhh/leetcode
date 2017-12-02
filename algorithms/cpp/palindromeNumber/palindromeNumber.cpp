// Source : https://leetcode.com/problems/palindrome-number/
// Author : Zhonghuan Gao
// Date   : 2017-12-02

/********************************************************************************** 
 * * 

 Determine whether an integer is a palindrome. Do this without extra space.

 *               
 ***********************************************************************************/


class Solution {
public:
    bool isPalindrome(int x) {
        // 回文数没有负数
        if (x < 0) return false;
        long long rev = reverse(x);
        if (rev == x) return true;
        return false;
    }
    long long reverse(int x) {
        // 反转越界判断
        long long rev = 0;
        while (x != 0) {
            rev = rev * 10  + x % 10;
            x /= 10;
        }
        return rev;
    }
    // 更多解法：http://qiemengdao.iteye.com/blog/1660227
};

