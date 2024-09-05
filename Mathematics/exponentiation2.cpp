// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long

// using namespace std;
// const int mod2 = 1e9 + 7;
// const long long INF = 1e18 + 5;
// ull powerit1(ull a, ull b)
// {
//     if(a==0 && b==0)return 1;
//     ull ans = 1;
//     ull mult = a;

//     while (b > 0)
//     {
//         if (b % 2 == 1)
//         {
//             ans = ans * mult ;
//         }

//         mult = (mult * mult) ;
//         b = b / 2;
//     }

//     return ans ;
// }

// ull powerit(ull a, ull b)
// {
//     if(a==0 && b==0)return 1;
//     ull ans = 1;
//     ull mult = a;

//     while (b > 0)
//     {
//         if (b % 2 == 1)
//         {
//             ans = ans * mult % mod2;
//         }

//         mult = (mult * mult) % mod2;
//         b = b / 2;
//     }

//     return ans % mod2;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     while (n--)
//     {
//         ll a, b, c;
//         cin >> a >> b >> c;

//         ull temp = powerit1(b, c);
//         cout << powerit(a, temp) << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
const int mod2 = 1e9 + 7;
const ull PHI_MOD2 = mod2 - 1;  // Since mod2 is prime, phi(mod2) = mod2 - 1

// Modular exponentiation function
ull powerit(ull a, ull b, ull mod) {
    if (a == 0 && b == 0) return 1;
    ull ans = 1;
    ull mult = a % mod;

    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * mult) % mod;
        }
        mult = (mult * mult) % mod;
        b = b / 2;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        // Compute b^c mod PHI_MOD2
        ull exponent = powerit(b, c, PHI_MOD2);

        // Compute a^exponent mod mod2
        cout << powerit(a, exponent, mod2) << endl;
    }

    return 0;
}
