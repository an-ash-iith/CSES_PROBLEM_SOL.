#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;
typedef pair<int, int> pi;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    queue<pi> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st[2];

    // Initialize start position and monster positions
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'M')
            {
                pq.push({i, j});
            }
            if (arr[i][j] == 'A')
            {
                st[0] = i;
                st[1] = j;
                arr[i][j] = '.';
            }
        }
    }

    vector<vector<int>> minstep(n, vector<int>(m, INT_MAX));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // BFS for monster's reachability
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int steps = 0;

    while (!pq.empty())
    {
        int size = pq.size();
        while (size--)
        {
            pi temp = pq.front();
            pq.pop();
            int row = temp.first, col = temp.second;

            if (minstep[row][col] != INT_MAX) continue;
            minstep[row][col] = steps;

            for (auto& dir : directions)
            {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && arr[newRow][newCol] == '.' && minstep[newRow][newCol] == INT_MAX)
                {
                    pq.push({newRow, newCol});
                }
            }
        }
        steps++;
    }

    // BFS for player's escape
    queue<pi> q;
    q.push({st[0], st[1]});
    visited[st[0]][st[1]] = -1;  // Mark start position
    bool found = false;
    pi end;

    steps = 0;
    while (!q.empty() && !found)
    {
        int size = q.size();
        while (size--)
        {
            pi temp = q.front();
            q.pop();
            int row = temp.first, col = temp.second;

            if (row == 0 || row == n - 1 || col == 0 || col == m - 1)
            {
                found = true;
                end = {row, col};
                break;
            }

            for (int i = 0; i < 4; ++i)
            {
                int newRow = row + directions[i][0], newCol = col + directions[i][1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && arr[newRow][newCol] == '.' && !visited[newRow][newCol] && minstep[newRow][newCol] > steps + 1)
                {
                    visited[newRow][newCol] = i + 1;  // Mark direction (1=L, 2=R, 3=U, 4=D)
                    q.push({newRow, newCol});
                }
            }
        }
        steps++;
    }

    if (!found)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        string ans;
        int row = end.first, col = end.second;

        while (!(row == st[0] && col == st[1]))
        {
            int dir = visited[row][col];
            if (dir == 1) { col++; ans += 'L'; }
            else if (dir == 2) { col--; ans += 'R'; }
            else if (dir == 3) { row++; ans += 'U'; }
            else if (dir == 4) { row--; ans += 'D'; }
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }

    return 0;
}
