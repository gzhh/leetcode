// Source : https://leetcode.com/problems/add-binary/
// Author : Zhonghuan Gao
// Date   : 2019-05-04

/********************************************************************************** 
*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*               
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一：
     * 先在较短字符串前面补'0'，使俩字符串长度一致。然后从后开始遍历，
     * 让两个字符对应的数字相加，相加的值有有四种结果，0、1、2、3，由
     * 两个字符对应数值和进位值相加得出，最后判断是否进位。
     */
    string addBinary(string a, string b) {
        int na = a.size(), nb = b.size();
        int n = max(na, nb);
        if (na > nb) {
            for (int i = 0; i < na - nb; i++) b.insert(b.begin(), '0');
        } else {
            for (int i = 0; i < nb - na; i++) a.insert(a.begin(), '0');
        }
        
        string sum;
        bool carry = false;
        for (int i = n - 1; i >= 0; i--) {
            int tmp = 0;
            if (carry) tmp = (a[i] - '0') + (b[i] - '0') + 1;
            else tmp = (a[i] - '0') + (b[i] - '0');
            if (tmp == 0 ) {
                sum.insert(sum.begin(), '0');
                carry = false;
            } else if (tmp == 1) {
                sum.insert(sum.begin(), '1');
                carry = false;
            } else if (tmp == 2) {
                sum.insert(sum.begin(), '0');
                carry = true;
            } else if (tmp == 3) {
                sum.insert(sum.begin(), '1');
                carry = true;
            }
        }
        
        if (carry) sum.insert(sum.begin(), '1');
        return sum;
    }

    /**
     * 解法二：
     * 用了两个指针分别指向a和b的末尾，然后每次取出一个字符，转为数字， 
     * 若无法取出字符则按0处理，并且拿到上一次的进位值，三者相加，
     * 对2取余即为当前位的数字，对2取商即为当前进位的值，
     */
    string addBinary(string a, string b)
    {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};
