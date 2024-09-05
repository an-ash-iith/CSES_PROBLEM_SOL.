#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;

ll findsum(ll sec, ll fst, ll val)
{
  sec = sec % mod2;
  fst = fst % mod2;

  ll sum_sec = (sec * (sec + 1) / 2) % mod2;
  ll sum_fst = (fst * (fst + 1) / 2) % mod2;
  ll count = (sum_sec - sum_fst + mod2) % mod2;

  return (count * val) % mod2; // Apply modular arithmetic step by step
}

int main()
{
  ll n;
  cin >> n;

  vector<ll> temp;
  ll ans = 0;

  for (ll i = 1; i * i <= n; i++)
  {
    ans = (ans + (n / i) * i % mod2) % mod2; // Ensure ans stays within mod2
  }

  int k = temp.size();

  ll low = 1ll * sqrt(n);

  for (int i = sqrt(n); i > 0; i--)
  {
    ll high = 1ll * n / i;
    ans = (ans + findsum(high, low, i)) % mod2; // Apply modulo after addition
    low =high;
  }

  // ans+=(n/k)*k;

  cout << ans << endl; // Final modulo operation
  return 0;
}
