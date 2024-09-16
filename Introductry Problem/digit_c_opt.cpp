#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll i = 1, sum = 0, prev_sum = 0, digits = 1;

        // Find the number of digits and the sum of all numbers with fewer digits
        while (sum < n) {
            prev_sum = sum;
            sum += 9 * i * digits;
            digits *= 10;
            i++;
        }

        // Calculate the number and digit position
        ll num = digits / 10 + (n - prev_sum - 1) / (i - 1);
        ll digit_pos = (n - prev_sum - 1) % (i - 1);

        // Convert the number to string
        string num_str = to_string(num);

        // Print the nth digit
        cout << num_str[digit_pos] << endl;
    }
    return 0;
}
