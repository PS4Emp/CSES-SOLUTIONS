#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    long int n;
    cin >> n;
    long int mx = 0; 
    ll ans = 0;

    for( int i = 0; i < n; ++i ){
        long int x;
        cin >> x;
        mx = max(x, mx);
        ans += mx-x;
    }
    cout << ans; 
}