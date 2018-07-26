#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * static bool isAnagram(string s, string t)
     * {
     *     sort(s.begin(), s.end());
     *     sort(t.begin(), t.end());
     *     return s == t;
     * }
     */
    static bool isAnagram(string s, string t)
    {
        if (s.length() != t.length()) return false;
        int len = s.length();
        int counts[26] = {0};
        for (int i = 0; i < len; i++) {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i] != 0) return false;
        return true;
    }
};


int main()
{
    string s, t;
    s = "anagram";
    t = "nagaram";
    if (Solution::isAnagram(s, t) == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

/*
Solution().methodName(); // 实例化一个类并调用类方法
Solution::methodName(); // 调用静态方法

// 初始化一个 vector 数组并赋值
int arr[] = {1, 2, 3};
vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[1]));
*/
