// Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

// this is the range update and point query  --

void build(int node, int st, int et, vector<ll> &tree, vector<ll> &arr)
{
    if (st == et)
    {
        tree[node] = arr[st];
        return;
    }

    int mid = (st + et) / 2;

    build(2 * node + 1, st, mid, tree, arr);
    build(2 * node + 2, mid + 1, et, tree, arr);

    tree[node] = 0; // as this is lazy propagation and no query till now so value is 0
}

void update(int node, int val, int l, int r, int st, int et, vector<ll> &tree)
{
    if (r < st || l > et)
    {
        return;
    }


    if (l <= st && et <= r)
    {
        tree[node] += val;
        return;
    }
   
    int mid = (st + et) / 2;
        update(2 * node + 1, val, l, r, st, mid, tree);
        update(2 * node + 2, val, l, r, mid + 1, et, tree);
    
}

ll findquery(int node, int ind, int st, int et, vector<ll> &tree)
{

    if (st == et)
        return tree[node];

    // lets write little bit code for the propagate ---
    tree[2 * node + 1] += tree[node];
    tree[2 * node + 2] += tree[node];
    tree[node] = 0;

    int mid = (st + et) / 2;

    if (ind <= mid)
        return findquery(2 * node + 1, ind, st, mid, tree);
    else
        return findquery(2 * node + 2, ind, mid + 1, et, tree);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> tree(4 * n);

    build(0, 0, n - 1, tree, arr);

    while (q--)
    {
        int a;
        cin >> a;

        if (a == 2)
        {
            int b;
            cin >> b;
            b--;

            cout << findquery(0, b, 0, n - 1, tree) << endl;
        }
        else
        {
            int c, d, f;
            cin >> c >> d >> f;
            c--;
            d--;
            update(0, f, c, d, 0, n - 1, tree);
        }
    }

    return 0;
}