#include <stdio.h>
#include <queue>
#include <string.h>
#include <string>

using namespace std;
typedef pair<int, pair <int, int>> is;


int main(){
  int n, p, cnt; char s[20];

	priority_queue<is,
			vector<is>,
			greater<is>> pq;

	while (scanf("%s", s), strcmp("#", s)) {
		scanf("%d %d", &n, &p);
		pq.push(pair<int, pair<int, int> >(p, pair<int, int>(n, p)));
	}

  scanf("%d", &cnt);
  is p1;
  while(cnt--){
   p1 = pq.top();
   pq.pop();
   printf("%d\n", p1.second.first);

  p1.first += p1.second.second;
	pq.push(p1);
  }

  return 0;
}