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
 
    int steps = 0;
 
    while (!pq.empty())
    {
        int size = pq.size();
 
        for (int i = 0; i < size; i++)
        {
            pi temp = pq.front();
            pq.pop();
 
            int row = temp.first;
            int col = temp.second;
                 
            minstep[row][col] = steps;
 
            // explore all the four possible direction --
            if (row < n - 1 && arr[row + 1][col] == '.' && minstep[row + 1][col] == INT_MAX)
            {
                pq.push({row + 1, col});
            }
            if (row >0 && arr[row - 1][col] == '.' && minstep[row - 1][col] == INT_MAX)
            {
                pq.push({row -1, col});
            }
            if (col < m - 1 && arr[row][col+1] == '.' && minstep[row][col+1] == INT_MAX)
            {
                pq.push({row, col+1});
            }
            if (col>0  && arr[row ][col-1] == '.' && minstep[row][col-1] == INT_MAX)
            {
                pq.push({row, col-1});
            }
        }
 
        steps++;
    }
 
    //we are ready with minsteps matrix where the monster can reach -- 
 
    //lets apply the bfs from the node -- from starting positon of A
   
 
       vector<vector<int>> visited(n, vector<int>(m, 0));
  
    queue<pi> q;
 
    q.push({st[0], st[1]});
        visited[st[0]][st[1]] = -1;  // Mark start position

    bool found = false;
 
    vector<int> end(2);
    
    int step =0;

    while (!q.empty() && !found)
    {
        int sz = q.size();
 
        for (int i = 0; i < sz; i++)
        {
            pi temp = q.front();
            q.pop();
 
            int row = temp.first;
            int col = temp.second;
            // cout<<row<<" "<<col<<endl;
 
            if (row ==n-1 || row==0 || col==0 || col == m-1)
            {
                found = true;
                end[0]=row;
                end[1]=col;
 
                break;
            }
 
            // go from all the four direction --
 
            if (minstep[row+1][col]>step+1 && !visited[row + 1][col] && arr[row + 1][col] == '.' )
            {
                visited[row + 1][col] = 4;
                q.push({row + 1, col});
                // cout<<"hi2"<<endl;
            }
            if (minstep[row-1][col]>step+1 && !visited[row - 1][col] && arr[row - 1][col] == '.')
            {
                visited[row - 1][col] = 3;
                q.push({row - 1, col});
                // cout<<"hi4"<<endl
            }
            if ( minstep[row][col+1]>step+1 &&!visited[row][col + 1] && arr[row][col + 1] == '.')
            {
                visited[row][col + 1] = 2;
                q.push({row, col + 1});
                // cout<<"hi3"<<endl;
            }
            if (minstep[row][col-1]>step+1 &&!visited[row][col - 1] && arr[row][col - 1] == '.')
            {
                visited[row][col - 1] = 1;
                q.push({row, col - 1});
                // cout<<"hi1"<<endl;
            }
        }

        step++;
 
        if (found)
            break;
    }
 
    if(!found)
    {
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
 
        // i will trace back from the node -- 
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

        //        while (!(row == st[0] && col == st[1]))
        // {
        //     int dir = visited[row][col];
        //     if (dir == 1) { col++; ans += 'L'; }
        //     else if (dir == 2) { col--; ans += 'R'; }
        //     else if (dir == 3) { row++; ans += 'U'; }
        //     else if (dir == 4) { row--; ans += 'D'; }
        // }
 
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
