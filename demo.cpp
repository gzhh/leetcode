#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int firstUniqChar(string s) {
        set<char> bucket;
        int n = s.length();
        for (int i = 0; i < n; i++)
            bucket.insert(s[i]);
        for (int i = 0; i < n; i++)
            if (bucket.count(s[i]) == 0) return i;
        return -1;
    }

    static char findTheDifference(string s, string t) {
        map<char, int> m;
        for (auto c : t) {
            m[c]++;
        }
        for (auto c : s) {
            m[c]--;
        }
        for (auto c : t) {
            if (m[c] == 1) return c;
        }
    }
};

int main()
{
    string s = "abccd";
    string t = "acbccd";
    cout << Solution::findTheDifference(s, t) << endl;

    /*
    int *p, i, j;
    i = 3, j = 4;
    p = max(&i, &j);
    
    printf("%p\n", p);
    printf("%d\n", *p);
    */
    return 0;
}

void *max(int *a, int *b)
{
    if (*a > *b)
        return a;
    else
        return b;
}



/*
Solution().methodName(); // 实例化一个类并调用类方法
Solution::methodName(); // 调用静态方法

// 初始化一个 vector 数组并赋值
int arr[] = {1, 2, 3};
vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[1]));
*/
