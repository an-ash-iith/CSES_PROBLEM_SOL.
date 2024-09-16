
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod2 = 1e9+7;

int main() {
    string s;
    cin >> s;

    ll n = s.length();
//this is similat to previous question -- only thing is if have to count then use similar concept to lower bound and upper bound 
// we know that difference between upper bound and lower bound of the array is count of the number of that element -- 

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

    int query;
    cin >> query;

    while (query--) {
        string temp;
        cin >> temp;
        
        int initial = 0;
        int final = n - 1;
        int length = temp.length();
        
        int leftind = -1;
        int rightind = -1;

        // Finding left index
        while (initial <= final) {
            int mid = (initial + final) / 2;
            int ind = track[mid].second;
            string comp = s.substr(ind, length);

            if (comp < temp) {
                initial = mid + 1;
            } else {
                final = mid - 1;
            }
        }
        leftind = initial;

        initial = 0;
        final = n - 1;

        // Finding right index
        while (initial <= final) {
            int mid = (initial + final) / 2;
            int ind = track[mid].second;
            string comp = s.substr(ind, length);

            if (comp <= temp) {
                initial = mid + 1;
            } else {
                final = mid - 1;
            }
        }
        rightind = initial;

        cout << max(0, rightind - leftind ) << endl;
    }
    return 0;
}

