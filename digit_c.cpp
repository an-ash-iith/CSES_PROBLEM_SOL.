#include <iostream>
#include <cmath>
#define max 1000000000000000000
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll val;
        ll i = 0;

        while (((ll)pow(10, i) * (9 * i - 1) + 1) / 9 < n) {
            i++;
        }

        // i denotes the number of digits
        ll j = i - 1;
        ll rest = n - ((ll)pow(10, j) * (9 * j - 1) + 1) / 9;

        ll x, y;

        x = rest / i;
        y = rest % i;

        ll final = (ll)pow(10, j) + x - 1;

        string ans1 = to_string(final);
        string ans2 = to_string(final + 1);

        if (y == 0) {
            cout << ans1[i - 1] << endl;
        } else {
            cout << ans2[y - 1] << endl;
        }
    }
    return 0;
}
