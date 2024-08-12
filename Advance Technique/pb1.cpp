// // #include <bits/stdc++.h>
// // #define ll long long
// // using namespace std;

// // void findAllSubsets(const vector<ll>& nums, ll sum, ll i, ll j, unordered_map<ll,ll> &mp, ll goal) {
// //     if (i == j) {
// //         mp[sum]++;
// //         return;
// //     }

// //     if (sum+nums[i] <= goal)
// //     findAllSubsets(nums, sum + nums[i], i + 1, j, mp, goal);
// //     findAllSubsets(nums, sum, i + 1, j, mp, goal);
// // }

// // ll countSum(const vector<ll>& nums, ll goal) {
// //     ll n = nums.size();
// //     ll k = n / 2;

// //     unordered_map<ll,ll> mp1, mp2;
    
// //     findAllSubsets(nums, 0, 0, k, mp1, goal);
// //     findAllSubsets(nums, 0, k, n, mp2, goal);

// //     ll count = 0;
// //     for (const auto& it : mp1) {
// //         ll complement = goal - it.first;
// //         if(complement>=0)
// //         {
// //         if (mp2.count(complement)) {
// //             count += it.second * mp2[complement];
// //         }
// //         }
// //     }

// //     return count;
// // }

// // int main() { 
// //     ll n, x;
// //     cin >> n >> x;

// //     vector<ll> nums(n);
// //     for (ll i = 0; i < n; i++) cin >> nums[i];

// //     cout << countSum(nums, x) << endl;

// //     return 0;
// // }
// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// // void findAllSubsets(const vector<ll>& nums, ll sum, ll i, ll j, unordered_map<ll, ll>& mp, ll goal) {
// //     if (sum > goal) return; // Early pruning if sum exceeds goal
// //     if (i == j) {
// //         mp[sum]++;
// //         return;
// //     }
// //     findAllSubsets(nums, sum + nums[i], i + 1, j, mp, goal);
// //     findAllSubsets(nums, sum, i + 1, j, mp, goal);
// // }

// ll countSum(const vector<ll>& nums, ll goal) {
//     ll n = nums.size();
//     ll k = n / 2;

//     unordered_map<ll, ll> mp1, mp2;

//     // findAllSubsets(nums, 0, 0, k, mp1, goal);
//     // findAllSubsets(nums, 0, k, n, mp2, goal);

//         // Generate all possible subset sums for the first half
//     for (ll i = 0; i < (1 << k); ++i) {
//         ll sum = 0;
//         for (ll j = 0; j < k; ++j) {
//             if (i & (1 << j)) {
//                 sum += nums[j];
//             }
//         }
//         mp1[sum]++;
//     }

//     // Generate all possible subset sums for the second half
//     for (ll i = 0; i < (1 << (n - k)); ++i) {
//         ll sum = 0;
//         for (ll j = 0; j < (n - k); ++j) {
//             if (i & (1 << j)) {
//                 sum += nums[k + j];
//             }
//         }
//         mp2[sum]++;
//     }

//     ll count = 0;
//     for (const auto& it : mp1) {
//         ll complement = goal - it.first;
//         if (mp2.count(complement)) {
//             count += it.second * mp2[complement];
//         }
//     }

//     return count;
// }

// int main() {
//     ll n, x;
//     cin >> n >> x;

//     vector<ll> nums(n);
//     for (ll i = 0; i < n; i++) cin >> nums[i];

//     cout << countSum(nums, x) << endl;

//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll countSum(const vector<ll>& nums, ll goal) {
    ll n = nums.size();
    ll k = n / 2;

    vector<ll> subset1, subset2;
    
    // Generate all possible subset sums for the first half
    for (ll i = 0; i < (1 << k); ++i) {
        ll sum = 0;
        for (ll j = 0; j < k; ++j) {
            if (i & (1 << j)) {
                sum += nums[j];
            }
        }
        subset1.push_back(sum);
    }

    // Generate all possible subset sums for the second half
    for (ll i = 0; i < (1 << (n - k)); ++i) {
        ll sum = 0;
        for (ll j = 0; j < (n - k); ++j) {
            if (i & (1 << j)) {
                sum += nums[k + j];
            }
        }
        subset2.push_back(sum);
    }

    // Sort the subset sums to use two-pointer or binary search technique
    sort(subset1.begin(), subset1.end());
    sort(subset2.begin(), subset2.end());

    ll count = 0;
    
    // Use two-pointer technique to find pairs of sums that add up to goal
    ll l = 0, r = subset2.size() - 1;
    while (l < subset1.size() && r >= 0) {
        ll current_sum = subset1[l] + subset2[r];
        if (current_sum == goal) {
            ll count1 = 1, count2 = 1;
            
            // Count identical values in subset1
            while (l + 1 < subset1.size() && subset1[l] == subset1[l + 1]) {
                count1++;
                l++;
            }
            // Count identical values in subset2
            while (r - 1 >= 0 && subset2[r] == subset2[r - 1]) {
                count2++;
                r--;
            }
            
            count += count1 * count2;
            l++;
            r--;
        } else if (current_sum < goal) {
            l++;
        } else {
            r--;
        }
    }

    return count;
}

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) cin >> nums[i];

    cout << countSum(nums, x) << endl;

    return 0;
}
