// // Author: Ashwin Kr.
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int mod2 = 1e9 + 7;
// const ll mod3 = 1000000000000000003LL;
// const ll INF = mod3;

// int dp[20001][31];  // 31 levels for binary lifting
// vector<int> tree[20001];

// void binarylifting(int node, int parent) {
//     dp[node][0] = parent;

//     for (int i = 1; i < 31; i++) {
//         if (dp[node][i - 1] != -1) {
//             dp[node][i] = dp[dp[node][i - 1]][i - 1];
//         } else {
//             dp[node][i] = -1;
//         }
//     }

//     // Process children
//     for (auto it : tree[node]) {
//         if (it != parent) {
//             binarylifting(it, node);
//         }
//     }
// }

// int findparent(int node, int level) {   
//     if (level == 0) return node;
    
//     for (int i = 30; i >= 0; i--) {
//         if ((1 << i) <= level) {
//             node = dp[node][i];
//             if (node == -1) return -1;  // If parent doesn't exist, return -1
//             level -= (1 << i);
//         }
//     }

//     return node;
// }

// int main() {
//     int n, q;
//     cin >> n >> q;

//     memset(dp, -1, sizeof(dp));  // Initialize dp with -1

//     for (int i = 2; i <= n; i++) { 
//         int a;
//         cin >> a;
//         tree[i].push_back(a);
//         tree[a].push_back(i);
//     }

//     binarylifting(1, -1);  // Initialize binary lifting from node 1 (general director)

//     while (q--) {
//         int src, level;
//         cin >> src >> level;
//         cout << findparent(src, level) << endl;
//     }

//     return 0;
// }


// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

vector<vector<int>> dp;  // Using a dynamic 2D vector
vector<vector<int>> tree;  // Dynamically sized tree

void binarylifting(int node, int parent) {
    dp[node][0] = parent;

    for (int i = 1; i < 31; i++) {
        if (dp[node][i - 1] != -1) {
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        } else {
            dp[node][i] = -1;
        }
    }

    // Process children
    for (auto it : tree[node]) {
        if (it != parent) {
            binarylifting(it, node);
        }
    }
}

int findparent(int node, int level) {   
    if (level == 0) return node;
    
    for (int i = 30; i >= 0; i--) {
        if ((1 << i) <= level) {
            node = dp[node][i];
            if (node == -1) return -1;  // If parent doesn't exist, return -1
            level -= (1 << i);
        }
    }

    return node;
}

int main() {
    int n, q;
    cin >> n >> q;

    // Dynamically allocate memory for dp and tree
    dp.resize(n + 1, vector<int>(31, -1));  // n+1 for 1-based indexing, 31 levels
    tree.resize(n + 1);  // Resizing the tree to size n+1

    for (int i = 2; i <= n; i++) { 
        int a;
        cin >> a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }

    binarylifting(1, -1);  // Initialize binary lifting from node 1 (general director)

    while (q--) {
        int src, level;
        cin >> src >> level;
        cout << findparent(src, level) << endl;
    }

    return 0;
}
