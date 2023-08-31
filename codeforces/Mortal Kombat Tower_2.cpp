#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int t;scanf("%d", &t);
  while(t--){
		int n;
		scanf("%d", &n);

		int bosses[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &bosses[j]);
		}

		/*
		 * dp[i][j] = the min amount of skip points
		 * on turn i (your turn is 0), on the jth boss.
		 * (1e9 to prevent overflow)
		 */
    int dp[2][n+10];
    memset(dp, 1e9, sizeof(dp));

		/*
		 * base case:
		 * your friend uses zero skip points before fighting any bosses.
		 */
		dp[1][0] = 0;

		for (int j = 0; j < n; j++) {
			// the opposite player switches on the previous move.
			dp[0][j + 1] = min(dp[0][j + 1], dp[1][j] + bosses[j]);
			dp[1][j + 1] = min(dp[1][j + 1], dp[0][j]);

			// the opposite player switches from the previous two moves.
			if (j + 2 <= n) {
				dp[0][j + 2] = min(dp[0][j + 2], dp[1][j] + bosses[j] + bosses[j + 1]);
				dp[1][j + 2] = min(dp[1][j + 2], dp[0][j]);
			}
		}
		printf("%d\n", min(dp[0][n], dp[1][n]));
	}
}
