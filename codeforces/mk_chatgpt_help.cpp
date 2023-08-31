#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int dp[n+1];
        // Initialize the base cases
        dp[0] = 0;
        dp[1] = a[0];
        dp[2] = a[0] < a[1] ? a[0] : a[1];  // min(a[0], a[1])
        // Fill up the dp array using the possible states
        for (int i = 3; i <= n; i++) {
            if (a[i-1] == 0) {
                dp[i] = dp[i-1];
            } else if (a[i-2] == 0) {
                dp[i] = dp[i-2] + 1;
            } else {
                dp[i] = dp[i-3] + 2;
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
