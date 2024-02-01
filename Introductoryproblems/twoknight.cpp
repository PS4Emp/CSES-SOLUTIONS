#include <iostream>

using namespace std;

typedef long long ll; 

int main() {
    int n;
    cin >> n;

    for( ll i = 1; i <= n; i++){
        ll total = (i * i) * (i * i-1) / 2;
        ll attack = 4 * (i -1) * (i -2);
        ll notAttack = total - attack; 
        cout << notAttack << "\n";
    }
}