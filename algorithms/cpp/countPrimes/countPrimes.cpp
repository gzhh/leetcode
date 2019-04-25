// Source : https://leetcode.com/problems/count-primes/
// Author : Zhonghuan Gao
// Date   : 2019-04-25

/********************************************************************************** 
**
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
** 
***********************************************************************************/

// 判断一个数是否是素数

/**
 * 解法一：判断是否被2 - sqrt(n)之间任意整数整除
 */
int isPrime(int n) {
    if (n == 2) return 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int countPrimes(int n) {
    int sum = 0;
    for (int i = 2; i < n; i++)
        if (isPrime(i)) sum++;
    return sum;
}


/**
 * 解法二：筛法
 * https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, true);
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int sum = 0;
        for (int i = 2; i < n; i++)
            if (prime[i]) sum++;
        return sum;
    }
};
