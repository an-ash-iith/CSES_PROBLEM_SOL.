// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
const int base = 31;

int main()
{
    string st;
    cin >> st;

    string bad;
    cin >> bad;

    int k;
    cin >> k;

    // so basicly we can tolerate k bad character in string -- so apply the brute force for string but
    // for comarison lets do string hashing time complexity will be n^2 *26 that is okay --

    // we have to apply brute approach in bit intelligent way so that hashing wont need anothe o(l) for the lenght string -
    int n = st.length();
    unordered_set<ll> sets;

    for (int i = 0; i < n; i++)
    {
        int badchar = 0;
        ll hash = 0;
        ll pow_val = 1;

        for (int j = i; j < n; j++)
        {
            if (bad[st[j]-'a'] == '0')
            {
                badchar++;
            }

            if (badchar <= k)
            {
                hash = (hash + (st[j] - 'a' + 1) * pow_val)%mod3;
                pow_val =(pow_val* base)%mod3;
                sets.insert(hash);
                // cout<<hash<<endl;
            }
            else
            {
                break;
            }
        }
    }

    cout<<sets.size()<<endl;

    return 0;
}