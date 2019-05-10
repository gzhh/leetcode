// Source : https://leetcode.com/problems/emonade-change/
// Author : Zhonghuan Gao
// Date   : 2019-05-10

/********************************************************************************** 
*
At a lemonade stand, each lemonade costs $5. 

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.

 

Example 1:

Input: [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: [5,5,10]
Output: true
Example 3:

Input: [10,10]
Output: false
Example 4:

Input: [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can't give change of $15 back because we only have two $10 bills.
Since not every customer received correct change, the answer is false.
*               
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一：
     * 5: cnt[5]++;
     * 10: cnt[10]++, cnt[5]--;
     * 20: cnt[10]--, cnt[5--] 或 cnt[5] -= 3
     * 只要 cnt[5] < 0，就 return false，否则最后 return true
     */
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mp;
        mp[5] = 0, mp[10] = 0;
        for (int i = 0, n = bills.size(); i < n; i++) {
            if (bills[i] == 5) mp[5]++;
            else if (bills[i] == 10) {
                if (mp[5] < 1) return false;
                mp[10]++;
                mp[5]--;
            } else {
                if (mp[5] > 0 && mp[10] > 0) {
                    mp[5]--;
                    mp[10]--;
                } else if (mp[5] > 2) {
                    mp[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * 解法一优化
     */
    bool lemonadeChange(vector<int> bills) {
        int five = 0, ten = 0;
        for (int i : bills) {
            if (i == 5) five++;
            else if (i == 10) five--, ten++;
            else if (ten > 0) ten--, five--;
            else five -= 3;
            if (five < 0) return false;
        }
        return true;
    }
};
