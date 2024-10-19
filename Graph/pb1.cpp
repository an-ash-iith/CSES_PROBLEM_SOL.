#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;

void check_subisland(vector<string> &grid2, vector<vector<int>> &visited, int row, int col)
{
    visited[row][col] = 1;

    int n = grid2.size();
    int m = grid2[0].size();

    // go to all 4 unvisted direction --

    if (row < n - 1 && !visited[row + 1][col] && grid2[row + 1][col] == '.')
    {
        check_subisland(grid2, visited, row + 1, col);
    }
    if (row > 0 && !visited[row - 1][col] && grid2[row - 1][col] == '.')
    {
        check_subisland(grid2, visited, row - 1, col);
    }
    if (col < m - 1 && !visited[row][col + 1] && grid2[row][col + 1] == '.')
    {
        check_subisland(grid2, visited, row, col + 1);
    }
    if (col > 0 && !visited[row][col - 1] && grid2[row][col - 1] == '.')
    {
        check_subisland(grid2, visited, row, col - 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin>>grid[i];
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                // go and visit and check it is subisland or not --
                check_subisland(grid, visited, i, j);
                count++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}