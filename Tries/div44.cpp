#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
     int n ,m;
     cin>>n>>m;
     
     char arr[n][m];
     int maxi=0;
     int col=0;
     int column=0;

     int row=0;
     int count=0;

     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        
     }
     

     for(int i =0;i<n;i++)
     {
        count=0;
        bool found=false;

        for(int j=0;j<m;j++)
        {
          

           if(arr[i][j]=='#')
           count++;

           if(count==1 && !found)
           {col=j;
             found=true;
           }
        }

        if(count>maxi)
        {
            maxi=count;
            row=i;
            column=col;
        }
     }
        // cout<<row<<" "<<maxi<<" "<<col<<endl;
        
         cout<<row+1<<" "<<(column+1+maxi/2)<<endl;
    }
return 0;
}