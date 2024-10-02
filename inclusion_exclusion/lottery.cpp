// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using the relation: LCM(a, b) = (a * b) / GCD(a, b)
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;  // To prevent overflow, first divide by gcd
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, m;
    cin >> r >> m;

    vector<ll> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    // this is the standard problem of inclusion and exclusion ---

    ll count = 0;

    for (int i = 1; i < (1 << m); i++)
    {
        int bits = 0;
        int val = i;
        int j = 0;
        ll lcmm = 1;
        bool overflow = false;

        while (val > 0)
        {
            if (val & 1)
            {
              
                lcmm = lcm(lcmm,arr[j]);
                bits++;
            }
            j++;
            val = val >> 1;
        }

        if (overflow)
            continue; // skip if overflow occurs

        if (bits & 1)
        {
            count += (r / lcmm);  // inclusion
        }
        else
        {
            count -= (r / lcmm);  // exclusion
        }
    }

    cout << r - count << endl;
    return 0;
}
