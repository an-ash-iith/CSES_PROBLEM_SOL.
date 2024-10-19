// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

// we have to use kmp algorithm --

// longest prefix that is also the suffix --

vector<int> KMP(string s)
{
    int n = s.length();
    // zindex[i] denotes the length of longest suffix which is also the prefix at string till i

    vector<int> zindex(n, 0);
    int j = 0;

    for (int i = 1; i < n; i++)
    {

        while (j != 0 || s[j] != s[i])
        {
            j = zindex[j - 1];
        }

        if (s[i] == s[j])
        {
            j++;
            zindex[i] = j;
        }
        else
        {
            zindex[i] = 0;
        }
    }

    return zindex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}