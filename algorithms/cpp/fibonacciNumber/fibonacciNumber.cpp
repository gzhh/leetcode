// Source : https://leetcode.com/problems/fibonacci-number/
// Author : Zhonghuan Gao
// Date   : 2019-04-13

/********************************************************************************** 
*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).
*               
**********************************************************************************/

class Solution {
public:
    /**
     * 递归
     */
    int fib(int N) {
        if (N == 0) return 0;
        else if (N == 1) return 1;
        return fib(N-1) + fib(N-2);
    }

    /**
     * 迭代
     */
    int fib(int N) {
        int a[N+2];
        a[0] = 0, a[1] = 1;
        for (int i = 2; i <= N; i++)
            a[i] = a[i-1] + a[i-2];
        return a[N];
    }
};
