//Author : Ashwin Kr
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void build(long long node, long long st, long long en, vector<long long> &arr, vector<long long> &tree)
{
    if (st == en)
    {
        tree[node] = arr[st];
        return;
    }
    long long mid = (st + en) / 2;

    build(2 * node + 1, st, mid, arr, tree);  // left portion
    build(2 * node + 2, mid + 1, en, arr, tree);

    tree[node] = min(tree[2 * node + 1] , tree[2 * node + 2]);
}

long long findmin(long long i, long long j, long long low, long long high, long long node, vector<long long> &tree)
{
    if (i <= low && high <= j)
        return tree[node];

    if (j < low || high < i)
        return INT_MAX;
    long long mid = (low + high) / 2;

    return min(findmin(i, j, low, mid, 2 * node + 1, tree) , findmin(i, j, mid + 1, high, 2 * node + 2, tree));
}

long long update(long long index, long long val, long long low, long long high, long long node, vector<long long> &tree)
{
    if (index < low || high < index)
        return tree[node];

    if (low == high && low == index)
    {
        tree[node] = val;
        return val;
    }

    long long mid = (low + high) / 2;

    tree[node] = min(update(index, val, low, mid, 2 * node + 1, tree),update(index, val, mid + 1, high, 2 * node + 2, tree));
    return tree[node];
}

int main()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> tree(4 * n, 0);

    build(0, 0, n - 1, arr, tree);

    while (q--)
    {
        long long type, a, b;
        cin >> type >> a >> b;
        a--;
        if (type == 1)
            update(a, b, 0, n - 1, 0, tree);  // first denotes index and second value to be updated
        else
        {
            b--;
            cout << findmin(a, b, 0, n - 1, 0, tree) << endl;
        }
    }

    return 0;
}
