#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod2 = 1e9 + 7;
const ll INF = 1e18 + 5;

ll powerit(ll num, ll exp, ll mod = mod2)
{
    ll ans = 1;
    num = num % mod;

    while (exp > 0)
    {
        if (exp % 2)
        {
            ans = (ans * num) % mod;
        }
        num = (num * num) % mod;
        exp /= 2;
    }

    return ans;
}

ll inverse(ll num, ll mod = mod2)
{
    // Fermat's Little Theorem: num^(mod-2) ≡ num^(-1) (mod mod) if mod is prime
    return powerit(num, mod - 2, mod);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    ll number = 1;  // Number of divisors
    ll sum = 1;     // Sum of divisors
    ll product = 1; // Product of divisors

    // Calculate number and sum of divisors
    for (int i = 0; i < n; i++)
    {
        // Number of divisors
        number = (number * (arr[i].second + 1)) % mod2;

        // Sum of divisors
        if (arr[i].first == 1)
        {
            sum = (sum + arr[i].second) % mod2;
        }
        else
        {
            ll base = arr[i].first;
            ll exponent = arr[i].second + 1;
            ll geom_sum = (powerit(base, exponent, mod2) - 1 + mod2) % mod2;

            ll inv = inverse(base - 1, mod2);
            sum = (sum * geom_sum % mod2 * inv % mod2) % mod2;
        }
    }

    // Calculate product of divisors
    ll exponent_sum = 1;  // Exponent sum for the product calculation

    for (int i = 0; i < n; i++)
    {
        exponent_sum = (exponent_sum * (arr[i].second + 1)) % (mod2 - 1);
    }

    for (int i = 0; i < n; i++)
    {
        ll exp_contrib = ((arr[i].second * exponent_sum) / 2) % (mod2 - 1);
        product = (product * powerit(arr[i].first, exp_contrib, mod2)) % mod2;
    }

    cout << (number + mod2) % mod2 << " " << (sum + mod2) % mod2 << " " << (product + mod2) % mod2 << endl;

    return 0;
}
