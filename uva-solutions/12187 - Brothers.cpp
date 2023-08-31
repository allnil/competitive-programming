#include <stdio.h>

int battleground[100][100];
int contested[100][100];

int N, R, C, K;

void out() {
  for (int i = 0; i < R; i++) {
    printf("%d", battleground[i][0]);
    for(int j = 1; j < C; j++) {
      printf(" %d", battleground[i][j]);
    }
    printf("\n");
  }
}

void fill() {
  for (int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      scanf("%d", &battleground[i][j]);
    }
  }
  for (int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      contested[i][j] = battleground[i][j];
    }
  }
}

void battle() {
  for (int k = 0; k < K; k++) {
    for (int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        if (i - 1 >= 0) {
          if ((battleground[i][j] + 1) == battleground[i-1][j] || 
            (battleground[i][j] == (N-1) && battleground[i-1][j] == 0)) {
            contested[i-1][j] = battleground[i][j];
          }
        };
        if (i + 1 < R) {
          if ((battleground[i][j] + 1) == battleground[i+1][j] || 
            (battleground[i][j] == (N-1) && battleground[i+1][j] == 0)) {
            contested[i+1][j] = battleground[i][j];
          }          
        };
        if (j - 1 >= 0) {
          if ((battleground[i][j] + 1) == battleground[i][j-1] || 
            (battleground[i][j] == (N-1) && battleground[i][j-1] == 0)) {
            contested[i][j-1] = battleground[i][j];
          }  
        };
        if (j + 1 < C) {
          if ((battleground[i][j] + 1) == battleground[i][j+1] || 
            (battleground[i][j] == (N-1) && battleground[i][j+1] == 0)) {
            contested[i][j+1] = battleground[i][j];
          }
        };
      }
    }
    for (int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        battleground[i][j] = contested[i][j];
      }
    }
  }
}

int main() {
  while(1) {
    scanf("%d %d %d %d", &N, &R, &C, &K);
    if (N==0 && R==0 && C==0 && K == 0) {
      break;
    }
    fill();
    battle();
    out();
  }
  return 0;
}