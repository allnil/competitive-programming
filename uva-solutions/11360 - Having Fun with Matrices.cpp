#include <stdio.h>
#include <string.h>

int m[9][9];
int tmp[9][9];

int N;
char strrow[100];

void fill() {
  for (int i = 0; i < N; i++) {
    scanf("%s", strrow);
    for(int j = 0; j < N; j++) {
      m[i][j] = strrow[j] - '0';
    }
  }
}

void out() {
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      printf("%d", m[i][j]);
    }
    printf("\n");
  }
}

void inc() {
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
     m[i][j] = (m[i][j]+1)%10;
    }
  }
}

void dec() {
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
     m[i][j] = ((m[i][j]-1)%10 + 10)%10;
    }
  }
}

void col(int a, int b) {
  a--;b--;
  for (int i = 0; i < N; i++) {
    int tmp = m[i][b];
    m[i][b] = m[i][a];
    m[i][a] = tmp;
  }
}

void row(int a, int b) {
  a--;b--;
  for (int i = 0; i < N; i++) {
    int tmp = m[b][i];
    m[b][i] = m[a][i];
    m[a][i] = tmp;
  }
}

void transpose(){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      tmp[i][j] = m[j][i];
    }
  }
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      m[i][j] = tmp[i][j];
    }
  }
}

int main() {
    int T, M, a,b, cases = 0;
    scanf("%d", &T);
    char op[20];
    while(T--){
      printf("Case #%d\n", ++cases);

      scanf("%d", &N);
      fill();

      scanf("%d", &M);
      while(M--){
        scanf("%s", op);
        if (strcmp(op, "inc") == 0){
          inc();
          continue;
        }
        if (strcmp(op, "dec") == 0){
          dec();
          continue;
        }
        if (strcmp(op, "row") == 0){
          scanf("%d %d", &a, &b);
          row(a,b);
          continue;
        }
        if (strcmp(op, "col") == 0){
          scanf("%d %d", &a, &b);
          col(a,b);
          continue;
        }
        if (strcmp(op, "transpose") == 0){
          transpose();
          continue;
        }
      }
      out();
      printf("\n");
    }

    return 0;
}