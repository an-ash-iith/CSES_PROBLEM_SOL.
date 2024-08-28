#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplyit(const vector<vector<int>>& v1, const vector<vector<int>>& v2) {
    int k = v1.size();
    vector<vector<int>> arr(k, vector<int>(k, 0));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            for (int m = 0; m < k; m++) {
                arr[i][j] += v1[i][m] * v2[m][j];
            }
        }
    }
    return arr;
}

vector<vector<int>> findpower(vector<vector<int>>& vec, int n) {
    if (n == 0) {
        int p = vec.size();
        vector<vector<int>> identity(p, vector<int>(p, 0));
        for (int i = 0; i < p; i++) identity[i][i] = 1;
        return identity;
    }

    if (n == 1) return vec;

    vector<vector<int>> halfPower = findpower(vec, n / 2);
    vector<vector<int>> fullPower = multiplyit(halfPower, halfPower);

    if (n % 2 != 0) {
        fullPower = multiplyit(fullPower, vec);
    }

    return fullPower;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec{{1, 1}, {1, 0}};

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> ans = findpower(vec, n - 1);

    // The n-th Fibonacci number is stored in ans[0][0]
    cout << ans[0][0] << endl;

    return 0;
}
