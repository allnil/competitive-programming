#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main(){
  int t; scanf("%d", &t);

  for(int i = 0; i < t; i++){
    
    bool field[100][100];
    int temp[100][100];
    queue<ii> rooks;

    for(int i = 0; i < 99; i++){
      for(int j = 0; j < 99; j++){
        temp[i][j] = 0;
      }
    }

    for(int i = 0; i < 99; i++){
      for(int j = 0; j < 99; j++){
        field[i][j] = false;
      }
    }

    int n,m;scanf("%d %d", &n, &m);
    
    for(int j = 0; j < m; j++){
      int x,y;scanf("%d %d", &x, &y); x--; y--;
      field[x][y] = true;
      ii p = {x,y};
      if(y - 1 > -1){
        temp[x][y-1] += 1;
      }
      if(y + 1 < n){
        temp[x][y+1] += 1;
      }
      if(x - 1 > - 1){
        temp[x-1][y] += 1;
      }
      if(x + 1 < n){
        temp[x+1][y] += 1;
      }
      rooks.push(p);
    }

    bool valid = false;
    while(!rooks.empty()){
      ii r = rooks.front(); rooks.pop();
      int x = r.first; int y = r.second;
      if(y - 1 > -1){
        if(temp[x][y-1] == 1 && !field[x][y-1]){
          valid = true;
        };
      }
      if(y + 1 < n){
        if(temp[x][y+1] == 1 && !field[x][y+1]){
          valid = true;
        };
      }

      if(x - 1 > - 1){
        if(temp[x-1][y] == 1 && !field[x-1][y]){
          valid = true;
        };
      }

      if(x + 1 < n){
        if(temp[x+1][y] == 1 && !field[x+1][y]){
          valid = true;
        };
      }
    }

    if(valid){
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}