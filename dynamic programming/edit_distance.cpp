//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
   string word1;
   string word2;
   cin>>word1>>word2;

   int n = word1.length();
   int m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

       //encountering the empty strings --- 

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else {
                    dp[i][j] = min({1+dp[i - 1][j], 1+dp[i][j - 1], 1+dp[i - 1][j - 1]});
                    
                }
            }
        }

        cout<< dp[n][m]<<endl;  // Final result for converting word1 to word2
return 0;
}