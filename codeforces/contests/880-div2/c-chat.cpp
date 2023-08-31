#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll getNumMin(ll n){
    return pow(10, n - 1);
}

ll getNumMax(ll n){
    return pow(10, n) - 1;
}

int main() {
    int t; cin >> t;
    while(t--) {
        ll a, b, c, k;
        cin >> a >> b >> c >> k;

        ll x = getNumMin(a);
        ll y = getNumMin(b);
        ll z = getNumMax(c);

        if(x + y > z){
            cout << -1 << endl;
            continue;
        }

        ll count = 0;
        for(ll sum = x + y; sum <= z; sum++) {
            ll min_a = max(x, sum - getNumMax(b));
            ll max_a = min(getNumMax(a), sum - y);
            if(min_a > max_a) continue;
            ll a_count = max_a - min_a + 1;
            ll min_b = max(y, sum - getNumMax(a));
            ll max_b = min(getNumMax(b), sum - x);
            if(min_b > max_b) continue;
            ll b_count = max_b - min_b + 1;
            count += a_count * b_count;
            if(count >= k) {
                ll a = max_a - (count - k) / b_count;
                ll b = max_b - (count - k) % b_count;
                cout << a << " + " << b << " = " << a + b << endl;
                break;
            }
        }

        if(count < k) cout << -1 << endl;
    }

    return 0;
}

