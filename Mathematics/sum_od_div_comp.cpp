#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;

ll findsum(ll sec, ll fst, ll val) {
    sec = sec % mod2;
    fst = fst % mod2;

    // Calculate the sum of numbers from fst+1 to sec
    ll sum_sec = (sec * (sec + 1) / 2) % mod2;
    ll sum_fst = (fst * (fst + 1) / 2) % mod2;
    ll count = (sum_sec - sum_fst + mod2) % mod2;

    return (count * val) % mod2;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> temp;
    ll ans = 0;

    for (ll i = 1; i * i <= n; i++) {
        temp.push_back(n / i);
        ans = (ans + (n / i) * i % mod2) % mod2;
    }

    int k = temp.size();

    for (int i = 1; i < k; i++) {
        ans = (ans + findsum(temp[i - 1], temp[i], i)) % mod2;
    }

    cout << ans << endl;
    return 0;
}
