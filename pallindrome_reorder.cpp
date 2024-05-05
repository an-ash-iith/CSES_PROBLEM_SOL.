#include <iostream>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }

    int count = 0;
    char mid = '\0'; // Initialize mid with null character
    for (int i = 0; i < 26; i++) {
        if (mp[char('A' + i)] % 2 == 1) {
            count++;
            mid = char('A' + i);
        }

        if (count > 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    stringstream ans;

    for (int i = 0; i < 26; i++) {
        char charec = char('A' + i);
        int val = mp[charec];

        for (int j = 0; j < val / 2; j++) {
            ans << charec;
        }
    }

    string leftHalf = ans.str();
    string rightHalf = leftHalf;
    reverse(rightHalf.begin(), rightHalf.end());

    if (mid != '\0') // Add mid character only if it exists
        cout << leftHalf + mid + rightHalf << endl;
    else
        cout << leftHalf + rightHalf << endl;

    return 0;
}


