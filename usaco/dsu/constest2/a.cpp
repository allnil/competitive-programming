#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

bool is_valid_pos(int x, int y, int rows, int cols) {
  return x >= 0 && x < rows && y >= 0 && y < cols;
}

vector<pair<int, int>> moves;

int bfs(pair<int, int> start, pair<int, int> target, int rows, int cols) {
  vector<vector<bool>> vis(rows, vector<bool>(cols, false));

  queue<pair<pair<int, int>, int>> q;

  q.push(make_pair(start, 0));

  while (!q.empty()) {
    auto [cur_pos, cur_distance] = q.front();
    q.pop();

    if (cur_pos == target) {
      return cur_distance;
    }

    for (auto &move : moves) {
      int new_x = cur_pos.first + move.first;
      int new_y = cur_pos.second + move.second;
      if (is_valid_pos(new_x, new_y, rows, cols) && !vis[new_x][new_y]) {
        vis[new_x][new_y] = true;
        q.push(make_pair(make_pair(new_x, new_y), cur_distance + 1));
      }
    }
  }

  return -1;
}

int main() {
  int t;
  cin >> t;
  moves.push_back(make_pair(-1, 1));
  moves.push_back(make_pair(-1, 0));

  for (int i = 0; i < t; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cols = abs(a - c) + 1;
    int rows = abs(b - d) + 1;
    int min_x = min(a, c);
    int min_y = min(b, d);
    pair<int, int> start(a - min_x, b - min_y);
    pair<int, int> target(c - min_x, d - min_y);

    cout << bfs(start, target, rows, cols) << endl;
  }
  return 0;
}
