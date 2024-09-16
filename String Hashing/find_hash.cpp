//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;

//the idea behind uses of const int rather than int is compiler can resuffle the code as these
//value are not goint to be changed in future and also it is not modifyable so less chance of mistake  -- 

const int p =31;  //this is the base , will be used for hashing 
const int q = 53;  //when both upper case and lower case letter is there you should use this

//even mod2 will lead to some collison but probility of this is very less -- s
//so for the practicle purpose we can use here --

ll computehash(string  &s)
{
    ll hashval=0;
    ll p_pow =1;

    for(char ch: s)
    {
        hashval=(hashval+(ch-'a'+1)*p_pow)%mod2;
        p_pow=(p_pow*p)%mod2;
    }

    return hashval;
}

int count_unique_substrings(string const& s) {
    int n = s.size();

    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % mod2;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod2;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + mod2 - h[i]) % mod2;
            cur_h = (cur_h * p_pow[n-i-1]) % mod2;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

int main()
{
 
 string s ="cricket";

 cout<<computehash(s)<<endl;


return 0;
}