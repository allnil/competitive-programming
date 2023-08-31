#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    // Reading the input
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    // Initializing the DP table
    ll d[51][51][2501] = {};

    // There's one way to select 0 cards from 0 cards with sum 0
    d[0][0][0] = 1;

    // Filling the DP table
    for(int i = 0; i < n; i++) {
        for(int k = 0; k <= i; k++) {
            for(int sum = 0; sum <= 2500; sum++) {
                // If sum is larger than the current card value
                if(sum >= a[i]) {
                    // We can select this card
                    d[i + 1][k + 1][sum] += d[i][k][sum - a[i]];
                }
                // We can also not select this card
                d[i + 1][k][sum] += d[i][k][sum];
            }
        }
    }

    // Calculating the answer
    ll ans = 0;
    for(int i = 1; i <= n; i++) 
        ans += d[n][i][i * m];

    cout << ans;

    return 0;
}

