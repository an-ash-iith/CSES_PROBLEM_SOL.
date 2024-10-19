#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;
int main()
{

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> matrix(n + 1, vector<ll>(n + 1, LLONG_MAX));

    //diagonal element should be initialize to 0 

    

    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        matrix[a][b] = min(matrix[a][b],c);
        matrix[b][a] = min(matrix[b][a],c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j){matrix[i][j]=0; continue;}
        

            for (int k = 1; k <= n; k++)
            {
                if (matrix[j][i] != LLONG_MAX && matrix[i][k] != LLONG_MAX)
                    matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == LLONG_MAX)
                matrix[i][j] = -1;
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        
        cout << matrix[a][b] << endl;
    }

    return 0;
}