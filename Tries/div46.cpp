#include <iostream>
#include <vector>
#include <climits>

#define ll long long

using namespace std;

bool checktrue(ll mid, vector<int> &arr, vector<int> &crr, int h) {
    ll turn = 0;
    ll temp = 0;

    for (int i = 0; i < arr.size(); i++) {
        temp = 1 + (mid - 1) /crr[i];

        if(temp>=h) return true;

         if (temp*arr[i] >= h)
            return true;

        turn += temp * arr[i];
        
        if (turn >= h)
            return true;
    }
    return turn >= h;
}

void binarys(ll mini, ll maxi, vector<int> &arr, vector<int> &crr, ll &ans, int &h) {
    if (mini > maxi) return;
      
    ll mid = mini + (maxi - mini) / 2;

    if (checktrue(mid, arr, crr, h)) {
        ans = mid;
        // cout<<"hi"<<mid<<" ";
        binarys(mini, mid - 1, arr, crr, ans, h);
    } else {
        binarys(mid + 1, maxi, arr, crr, ans, h);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, n;
        cin >> h >> n;

        vector<int> arr(n);
        vector<int> crr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> crr[i];
        }

        // This question is binary search -- guess and verify

        // And greedy--

        ll mini = 1; // in one turn
        ll maxi = LLONG_MAX / 2; // Adjusted max to prevent overflow
        ll ans = LLONG_MAX / 2;
        binarys(mini, maxi, arr, crr, ans, h);

        cout << ans << endl;
    }

    return 0;
}
