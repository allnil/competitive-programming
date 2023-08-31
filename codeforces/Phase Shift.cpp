#include<stdio.h>
#include <cstring>
#include <vector>
#include <string>

const int N = 200070;

using namespace std;

void solve(){
  int n;
  char ct[N];
  string t;

  scanf("%d", &n);
  scanf("%s",ct);
  t = ct;
	vector<int> edge(26, -1);
	vector<int> redge(26, -1);

	auto get_path_end = [&](int c) {
		int len = 0;
		int cur = c;
		while (edge[cur] != -1)
			len++, cur = edge[cur];
		return make_pair(cur, len);
	};

	vector<int> vec;
	for (auto c : t)
		vec.push_back(c - 'a');

	for (int i = 0; i < n; i++) {
		if (edge[vec[i]] == -1) {
			for (int c = 0; c < 26; c++)
				if (redge[c] == -1) {
					auto [clast, len] = get_path_end(c);
					if (clast != vec[i] || len == 25) {
						edge[vec[i]] = c;
						redge[c] = vec[i];
						break;
					}
				}
		}
		vec[i] = edge[vec[i]];
	}

	for (int i = 0; i < n; i++){
    t[i] = vec[i] + 'a';
    printf("%c", t[i]);
  }
  printf("\n"); 
}


int main(){
  int t; scanf("%d", &t);
  while(t--)
    solve();
  return 0;
}