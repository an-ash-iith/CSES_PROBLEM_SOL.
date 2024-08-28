#include <iostream>
#include <vector>
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<ll>> multiplyit(const vector<vector<ll>>& v1, const vector<vector<ll>>& v2) {
    int k = v1.size();
    vector<vector<ll>> arr(k, vector<ll>(k, 0));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            for (int m = 0; m < k; m++) {

                
                arr[i][j] = (arr[i][j]%mod+(v1[i][m] * v2[m][j])%mod;
                arr[i][j]=arr[i][j]%mod;
            }
        }
    }
    return arr;
}

vector<vector<ll>> findpower(vector<vector<ll>>& vec, int n) {
    if (n == 0) {
        int p = vec.size();
        vector<vector<ll>> identity(p, vector<ll>(p, 0));
        for (int i = 0; i < p; i++) identity[i][i] = 1;
        return identity;
    }

    if (n == 1) return vec;

    vector<vector<ll>> halfPower = findpower(vec, n / 2);
    vector<vector<ll>> fullPower = multiplyit(halfPower, halfPower);

    if (n % 2 != 0) {
        fullPower = multiplyit(fullPower, vec);
    }

    return fullPower;
}

int main() {
   ll n;
    cin >> n;

    vector<vector<ll>> vec{{3, 1}, {1, 3}};

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<vector<ll>> ans = findpower(vec, n );

    
    cout << ans[0][0]%mod << endl;

    return 0;
}
