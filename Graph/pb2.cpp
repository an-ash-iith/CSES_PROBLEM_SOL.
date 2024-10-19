#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const long long INF = 1e18 + 5;
typedef pair<int, int> pii;

int main()
{
    // to find the shortest path -- bfs is key algorithm --
    // along with that to keep track record i will also keep the step done by previous one to reach that --

    // there are 4 move 1,2,3,4 for left right, up and down

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);

    int st[2];
    int end[2];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'A')
            {
                st[0] = i;
                st[1] = j;
            }

            if (arr[i][j] == 'B')
            {
                end[0] = i;
                end[1] = j;
                arr[i][j]='.';
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pii> q;

    q.push({st[0], st[1]});

    bool found = false;

    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            pii temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;
            // cout<<row<<" "<<col<<endl;

            if (row == end[0] && col == end[1])
            {
                found = true;
                break;
            }

            // go from all the four direction --

            if (row < n - 1 && !visited[row + 1][col] && arr[row + 1][col] == '.' )
            {
                visited[row + 1][col] = 4;
                q.push({row + 1, col});
                // cout<<"hi2"<<endl;
            }
            if (row > 0 && !visited[row - 1][col] && arr[row - 1][col] == '.')
            {
                visited[row - 1][col] = 3;
                q.push({row - 1, col});
                // cout<<"hi4"<<endl
            }
            if (col < m - 1 && !visited[row][col + 1] && arr[row][col + 1] == '.')
            {
                visited[row][col + 1] = 2;
                q.push({row, col + 1});
                // cout<<"hi3"<<endl;
            }
            if (col > 0 && !visited[row][col - 1] && arr[row][col - 1] == '.')
            {
                visited[row][col - 1] = 1;
                q.push({row, col - 1});
                // cout<<"hi1"<<endl;
            }
        }

        if (found)
            break;
    }

    if(!found)
    {
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;

        //i will trace back from the node -- 
        string ans;

        int row = end[0];
        int col = end[1];

        while(!(row==st[0] && col==st[1]))
        {
            if(visited[row][col]==1)
            {   
                col++;
                ans+='L';
            }else if(visited[row][col]==2)
            {   col--;
                ans+='R';
            }
            else if(visited[row][col]==3)
            {   
                row++;
                ans+='U';
            }else{

                row--;
                ans+='D';
            }
        }

        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }

    return 0;
}