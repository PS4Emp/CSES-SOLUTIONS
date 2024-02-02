#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

ll power(ll base, ll exponent, ll mod) {
    ll result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}

int main() {
    ll n;  // Assuming n is of type long long, adjust if necessary
    cin >> n;

    long long result = power(2, n, MOD);

    cout << result << endl;

    return 0;
}
