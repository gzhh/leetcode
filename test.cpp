#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (g[i] <= s[j]) {
                count++;
                s.erase(s.begin()+j);
                break;
            }
        }
    }
    return count;
}

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int index_g = 0;
    int index_s = 0;
    while (index_g < g.size() && index_s < s.size()) {
        if (g[index_g] <= s[index_s]) {
            index_g++;
            index_s++;
        } else {
            index_s++;
        }
    }
    return index_g;
}

int main()
{
    // int a1[] = {1,2,3};
    // int a2[] = {1,1};
    // int a1[] = {1,2};
    // int a2[] = {1,2,3};
    // int a1[] = {1,2,3,4,5};
    // int a2[] = {1,3,2,2};
    int a1[] = {10,9,8,7};
    int a2[] = {5,6,7,8};
    int a1_len = sizeof(a1) / sizeof(a1[0]); 
    int a2_len = sizeof(a2) / sizeof(a2[0]); 
    
    vector<int> v1(a1, a1+a1_len), v2(a2, a2+a2_len);
    // for (int i = 0; i < a2_len; i++) {
    //    cout << v2[i] << " ";
    // }
    cout << findContentChildren(v1, v2);
    cout << endl;
    return 0;
}
