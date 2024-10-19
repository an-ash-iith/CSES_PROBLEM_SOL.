//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);

return 0;
}
class Solution {
public:

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

    int minimumTimeToInitialState(string word, int k) {
        string s = word;
        // string temp = word + '#' + s;  // Combine word, separator, and word again

        vector<int> pre = z_function(s);
        
        int n = word.size();
        
        int mini=ceil((double)n/k);
        int cnt=0;
        for(int i=k;i<n;i+=k)
        {
             cnt++;

             if(pre[i]== n-i)
             {
                mini=min(mini,cnt); 
             }
        }

        return mini;
    }
};
