#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int t;scanf("%d", &t);
  while(t--){
		int n;
		scanf("%d", &n);

    vector<int> a(n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

    vector<int> him(n+1);
    vector<int> us(n+1);
    him[n]=us[n]=0;

		for (int i = n - 1; i >= 0; i--) {
      // calculate him[i]
      {
        him[i] = us[i+1] + a[i];
        if(i + 2 <= n){
          him[i] = min(him[i], us[i + 2] + a[i] + a[i+1]);
        }
      }
      // calculate us[i]
      {
        us[i] = him[i+1];
        if(i + 2 <= n){
          us[i] = min(us[i], him[i + 2]);
        }
      }
		}
    printf("%d\n", him[0]);
	}
  return 0;
}
