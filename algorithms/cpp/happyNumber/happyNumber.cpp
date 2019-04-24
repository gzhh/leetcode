// Source : https://leetcode.com/problems/happy-number/
// Author : Zhonghuan Gao
// Date   : 2019-04-24

/********************************************************************************** 
* 
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*               
***********************************************************************************/

/**
 * 思路一：用 HashSet 来记录所有出现过的数字，然后每出现一个新数字，在 HashSet 中查找看是否存在，
 * 若不存在则加入表中，若存在则跳出循环，并且判断此数是否为1，若为1返回true，不为1返回false。
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum;
        while (n != 1) {
            sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (s.count(n)) break;
            s.insert(n);
        }
        return n == 1;
    }
};


/**
 * 思路二：快慢指针解法，类似于单链表判断环问题
 */
int digitSquareSum(int n)
{
    int sum = 0, res;
    while (n) {
        res = n % 10;
        sum += res * res;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow = n, fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while (slow != fast);
    if (slow == 1) return true;
    return false;
}
