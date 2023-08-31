#include "stdio.h"
#include <cstdio>

int row[8], a, b;

bool canPlace(int r, int c){
  for(int prev = 0; prev < c; ++preve)
    if (( row[prev] == r) || (abs(row[prev]-r) == abs(prev - c)))
      return false;
  return true;
}

void backtrack(int c) {
  if ((c==8) && (row[b] == a)) {
    printf("%2d      %d", ++lineCounter, row[0]+1);
    for(int j = 1; j < 8; ++j) printf(" %d", row[j]+1);
    printf("\n");
    return;
  }
  for (int r = 0; r < 8; ++r) {
    if((c == b) && ( r != a)) continue;
    if (canPlace(r, c)
        row[c] = r, backtrack(c+1);
        }
}

int main() {
  int TC;
  scanf("%d", &TC);

  while (TC--) {
    scanf("%d %d" ,&a, &b; --a, --b;
    memset(row, 0, sizeof row);
    printf("SOLN      COLUMN\n);
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);
    if (TC) printf("\n");
  }
  return 0;
}
