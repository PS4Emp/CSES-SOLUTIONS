#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = 0; 

    for( ll i=5; i <=n; i*=5) {
        ans += n/i;
    }

    cout << ans; 
}