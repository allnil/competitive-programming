#include <stdio.h>
#include <string>

/*
There will be at most 20 test cases. Each test case begins with two integers n and m (1 ≤ m ≤ n ≤ 10)
in a single line. The next n lines describe the large polyomino. Each of these lines contains exactly n
characters in ‘*’,‘.’. A ‘*’ indicates an existing square, and a ‘.’ indicates an empty square. The next
m lines describe the small polyomino, in the same format. These characters are guaranteed to form
valid polyominoes (note that a polyomino contains at least one existing square). The input terminates
with n = m = 0, which should not be processed.

Output
For each case, print ‘1’ if the corresponding composing is possible, print ‘0’ otherwise.
*/

char p[10][20];

int main() {
  int n, m = 0;
  char row[20];
  while (scanf("%d %d", &n, &m) == 2)
  {
    while(n--){
      scanf("%s", row);
    }
    while(m--){
      scanf("%s", row);
    }

    int res = 0;
    printf("%d\n", res);
  }

  

  return 0;
}