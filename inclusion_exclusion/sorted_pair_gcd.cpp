//Author: Ashwin Kr.
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod2 = 1e9 + 7;
const ll mod3 = 1000000000000000003LL;
const ll INF = mod3;
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        // this question would have been very easy if it have told to find the
        // distinct pair --
        // the problem coming in this is i am not able to track which
        // from the hint i got to know that for i have to count for every gcd

        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> count(maxi+1, 0);
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            int val = nums[j];
            int i;
            for (i = 1; i * i < val; ++i)
                if (val % i == 0) {
                    count[i]++;
                    count[val / i]++;
                }

            if (i * i == val) {
                count[i]++;
            }
        }

        // cout<<count[maxi]<<endl;

        // i am ready with all the factor of the given number in o(n*rootn)

        // this is not actually inclusion but indeed only exclusion --
        vector<long long> gcdcount(maxi + 1, 0);

        // will keep the count the number of the gcd with the given maxi ---

        for (int i = maxi; i > 0; i--) {
            long long temp = 0;

            if(count[i]==0) continue;

            for (int j = 2 * i; j <= maxi;
                 j += i) // subtract the all the factor count of j as these are
                         // already
            // included in higher gcd value whose this is factor
            {
                temp += gcdcount[j];
            }
        //   if(i==maxi) cout<<count[i]<<" "<<temp<<endl;
            gcdcount[i] =(1LL*count[i]*(count[i]-1))/2 - temp; // make sure to cast to long long
        }

        // this above have approx o(max_element^2) time complexity -- but all have done like this 
        // it is a bit optimis because for the most element it should work 

        // i am ready with this things -- 
        //lets find the pregcd -- 

        // for(int i=0;i<=maxi;i++)
        // {
        //     cout<<gcdcount[i]<<" ";
        // }
        for(int i=1;i<=maxi;i++)
        {
            gcdcount[i]+=gcdcount[i-1];
        }

        vector<int> ans;

        for(auto it: queries)
        {
            int ind = lower_bound(gcdcount.begin(),gcdcount.end(),it+1)-gcdcount.begin();
            ans.push_back(ind);
        }

        return ans;

    }
};

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);

Solution s1;
// s1.gcdValues();
return 0;
}