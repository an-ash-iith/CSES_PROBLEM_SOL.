// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
const int mod4 = 998244353;

ll total_pos(ll num, ll maxi)
{
  
    vector<ll> temp;
    ll cnt = 0;

    // Corrected prime factorization logic
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
            {
                num /= i;
            }
            temp.push_back(i); // Push the prime factor 'i', not 'num'
        }
    }

    if (num > 1) // If there is any prime factor greater than sqrt(num)
        temp.push_back(num);

    ll sum = 0;
    for (int msk = 1; msk < (1 << temp.size()); ++msk)
    {
        ll mult = 1, bits = 0;
        for (int i = 0; i < (int)temp.size(); ++i)
            if (msk & (1 << i))
            {
                ++bits;
                mult *= temp[i];
            }

        ll cur = maxi / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }

    return maxi - sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> gcdval(n);
        for (int i = 0; i < n; i++)
            cin >> gcdval[i];

        ll prevgcd = gcdval[0];
        ll count = 1;

        for (int i = 1; i < n; i++)
        {
            if (gcdval[i] > prevgcd)
            {
                count = 0;
                break;
            }

            ll temp = prevgcd / __gcd(prevgcd, gcdval[i]);

            prevgcd = __gcd(prevgcd, gcdval[i]);

            if (prevgcd == 1 && gcdval[i] != 1)
            {
                count = 0;
                break;
            }

            ll maxi = m / prevgcd;
            ll mult = total_pos(temp, maxi);
            count = (count * mult) % mod4;
        }

        cout << count << endl;
    }
    return 0;
}
