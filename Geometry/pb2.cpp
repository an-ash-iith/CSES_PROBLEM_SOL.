// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int mod2 = 1e9+7; 

// void finddirection(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
// {
//     // vec1   (x2-x1)i +(y2-y1)j
//     // vec2   (x3-x1)i+ (y3-y1)j 

//     ll or1 = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
//     ll or2 = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);

//     ll or3 = (x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3);
//     ll or4 = (x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3);

//     // cout << or1 << " " << or2 << " " << or3 << " " << or4 << endl;
  
//     if (or1 * or2 < 0 && or3 * or4 < 0) {
//         cout << "YES" << endl;
//     } else {  
//         if (or1 == 0) {
//             if ((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) + (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) == (x2 - x1) * (x2 - x1) + (y2 - x1) * (y2 - x1)) {
//                 cout << "YES" << endl;
//                 return;
//             }      
//         }

//         if (or2 == 0) {
//             if ((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4) + (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4) == (x2 - x1) * (x2 - x1) + (y2 - x1) * (y2 - x1)) {
//                 cout << "YES" << endl;
//                 return;
//             }      
//         }

//         if (or3 == 0) {
//             if ((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) + (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4) == (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3)) {
//                 cout << "YES" << endl;
//                 return;
//             }      
//         }

//         if (or4 == 0) {
//             if ((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) + (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4) == (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3)) {
//                 cout << "YES" << endl;
//                 return;
//             }      
//         }
        
//         cout << "NO" << endl;
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--) {
//         ll x1, y1, x2, y2, x3, y3, x4, y4;
//         cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

//         finddirection(x1, y1, x2, y2, x3, y3, x4, y4);
//     }
//     return 0;
// }


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7; 

void finddirection(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
    // vec1   (x2-x1)i +(y2-y1)j
    // vec2   (x3-x1)i+ (y3-y1)j 

    ll or1 = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    ll or2 = (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1);

    ll or3 = (x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3);
    ll or4 = (x4 - x3) * (y2 - y3) - (x2 - x3) * (y4 - y3);

    cout << or1 << " " << or2 << " " << or3 << " " << or4 << endl;
  
    if (or1 * or2 < 0 && or3 * or4 < 0) {
        cout << "YES" << endl;
    } else {  
        if (or1 == 0 && min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2)) {
            cout << "YES" << endl;
            return;
        }

        if (or2 == 0 && min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y1, y2) <= y4 && y4 <= max(y1, y2)) {
            cout << "YES" << endl;
            return;
        }

        if (or3 == 0 && min(x3, x4) <= x1 && x1 <= max(x3, x4) && min(y3, y4) <= y1 && y1 <= max(y3, y4)) {
            cout << "YES" << endl;
            return;
        }

        if (or4 == 0 && min(x3, x4) <= x2 && x2 <= max(x3, x4) && min(y3, y4) <= y2 && y2 <= max(y3, y4)) {
            cout << "YES" << endl;
            return;
        }
        
        cout << "NO" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        finddirection(x1, y1, x2, y2, x3, y3, x4, y4);
    }
    return 0;
}
