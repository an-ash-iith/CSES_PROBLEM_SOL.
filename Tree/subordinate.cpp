#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;

int traverse(int node, vector<int> &count, vector<vector<int>> &child)
{  
    int total=0;

    for(int i=0;i<child[node].size();i++)
    {
       total+=traverse(child[node][i],count,child);
    }
 
 count[node]=total;
    return total+1;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> child(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;

        child[a].push_back(i);
    }

    vector<int> count(n + 1, 0);
    traverse(1, count, child);

    for (int i = 1; i <= n; i++)
    {
        cout << count[i] << " ";
    }

    cout << endl;

    return 0;
}
