#include "stdio.h"
#include <cstdio>
#include <cstring>
#include "algorithm"

using namespace std;

int memo[200][20];
int g[20][20];
int ng[20];
int TC, m, c;

int shop(int money, int curG) {
	if (money < 0)
		return -1e6;
	if (curG == c)
		return m - money;

	if (memo[money][curG] != -1)
		return memo[money][curG];

	int ans = -1e6;
	for (int i = 0; i < ng[curG]; i++) {
		ans = max(ans, shop(money - g[curG][i], curG + 1));
	}

	return memo[money][curG] = ans;
}

int main(){
  int TC; scanf("%d", &TC);
  while(TC--){
    scanf("%d %d", &m, &c);
		for (int i = 0; i < c; i++) {
			scanf("%d", &ng[i]);
			for (int j = 0; j < ng[i]; j++) {
				scanf("%d", &g[i][j]);
			}
		}
    memset(memo, -1, sizeof memo);  // clear everything

		int ans = shop(m, 0);

		if (ans > 0)
			printf("%d\n", ans);
		else
			printf("no solution\n");
  }
  return 0;
}

