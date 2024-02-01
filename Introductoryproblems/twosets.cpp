#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll sum = (n * (n + 1)) / 2;
    vector<ll> set1, set2;

    if (sum % 2 == 0) {
        cout << "YES\n";
        ll mid = sum / 2;

        for (int i = n; i >= 1; i--) {
            if (i <= mid) {
                set1.push_back(i);
                mid = mid - i;
            } else {
                set2.push_back(i);
            }
        }

        cout << set1.size() << "\n";
        for (ll i = 0; i < (int)set1.size(); i++)
            cout << set1[i] << " ";
        cout << "\n";
        cout << set2.size() << "\n";
        for (ll i = 0; i < (int)set2.size(); i++)
            cout << set2[i] << " ";
    } else {
        cout << "NO";
    }

    return 0;
}
