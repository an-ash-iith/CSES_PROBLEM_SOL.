#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod2 = 1e9+7;

int main() {
    string s;
    cin >> s;

    ll n = s.length();


    // It may seem that it can be done in O(n log n) using brute force, like
    // traverse from the back and keep pushing to a map or simply vector, or at last sort if not -- 
    // so it will take n log(n), but hold on. If you go to the basic merge sort, the height of the tree will be log(n),
    // and the time for merging will be O(n).
    // As comparison there has taken O(1) time, but comparing two strings of the average length n/2 will take O(n) time,
    // so the combined merger and compare operator lead to O(n^2).
    // Thus, the total time complexity becomes n^2 log(n), which is not tolerable.

    // So we have to use suffix array methodology that can do this in O(n(logn)^2).


    s.push_back('$');
    n++;

    vector<pair<ll, ll>> track(n);

    for (ll i = 0; i < n; i++) {
        track[i] = {s[i], i};  // Here ASCII value will go.
    }

    sort(track.begin(), track.end());

    ll id = 0;
    vector<ll> idno(n);

    for (ll i = 0; i < n; i++) {
        if (i > 0 && track[i].first != track[i - 1].first) id++;
        idno[track[i].second] = id;
    }

    ll current = 1;
    ll k = 1;

    while (current < n) {
        for (ll i = 0; i < n; i++) {
            track[i].first = idno[i] * 1000000 + idno[(i + current) % n];
            track[i].second = i;
        }

        sort(track.begin(), track.end());

        id = 0;

        for (ll i = 0; i < n; i++) {
            if (i > 0 && track[i].first != track[i - 1].first) id++;
            idno[track[i].second] = id;
        }

        k++;
        current *= 2;
    }

    for (ll i = 0; i < n; i++) {
        cout << track[i].second << " ";
    }

cout<<endl;
    return 0;
}
