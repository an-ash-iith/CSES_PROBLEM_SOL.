// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

vector<vector<int>> dp;  // Using a dynamic 2D vector
vector<vector<int>> tree;  // Dynamically sized tree
vector<int> level(200001);

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
            level[it] = level[node] + 1;
            binarylifting(it, node);
        }
    }
}

int findparent(int node, int k) {   
    for (int i = 30; i >= 0; i--) {
        if ((1 << i) <= k) {
            node = dp[node][i];
            if (node == -1) return -1;  // If parent doesn't exist, return -1
            k -= (1 << i);
        }
    }

    return node;
}

int lca2(int node1, int node2) {
    // Bring node1 and node2 to the same level
    if (level[node1] > level[node2]) swap(node1, node2);

    int diff = level[node2] - level[node1];
    node2 = findparent(node2, diff);  // Lift node2 up by the difference in levels

    if (node1 == node2) return node1;

    // Apply binary lifting to find the LCA
    for (int i = 30; i >= 0; i--) {
        if (dp[node1][i] != dp[node2][i]) {
            node1 = dp[node1][i];
            node2 = dp[node2][i];
        }
    }

    return dp[node1][0];  // Return the parent of node1 (or node2) which is the LCA
}

int lca1(int node1, int node2)
{
    //you have to find lca of the both  -- 
    //lets make the label of both as same 

    if(node1==node2) return node1;

    if(level[node1]>level[node2])
    {
        swap(node1,node2);
    }

    int diff= level[node2]-level[node1];

     node2= findparent(node2,diff);  


    //now both the node are at the same level -- 

    //lets apply the binary search  --- 

    int ans =0;

    int st =0; int end = level[node2];  //this is the max height where you will be able to find the ancestor

    while(st<=end)
    {
        int mid = (st+end)/2;

        if(findparent(node1,mid)==findparent(node2,mid))
        {
            ans=mid;
            end= mid-1;
        }else 
          st= mid+1;
    }

    return findparent(node1,ans);
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

    level[1] = 0;  // Root node at level 0
    binarylifting(1, -1);  // Initialize binary lifting from node 1 (general director)

    while (q--) {
        int node1, node2;
        cin >> node1 >> node2;
        cout << lca1(node1, node2) << endl;
    }

    return 0;
}
