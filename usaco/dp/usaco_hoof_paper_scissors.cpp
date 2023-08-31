#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define sz(x) (int) (x).size()


void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int maxGamesWon(int N, int K, const vector<char>& moves) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(3, 0)));
    string gestures = "HPS";
    
    for (int i = 1; i <= N; ++i) {
        for (int k = 0; k <= K; ++k) {
            for (int j = 0; j < 3; ++j) {
                int wins = dp[i - 1][k][j] + (moves[i - 1] == gestures[(j + 1) % 3]);
                if (k > 0) {
                    wins = max(wins, max(dp[i - 1][k - 1][(j + 1) % 3], dp[i - 1][k - 1][(j + 2) % 3]) + (moves[i - 1] == gestures[(j + 1) % 3]));
                }
                dp[i][k][j] = wins;
            }
        }
    }

    int max_wins = 0;
    for (int j = 0; j < 3; ++j) {
        max_wins = max(max_wins, dp[N][K][j]);
    }
    
    return max_wins;
}


int main(){
  setIO("hps");
  int N, K;
  cin >> N >> K;
  vector<char> moves(N);

  for(int i = 0; i < N; ++i){
    cin >> moves[i];
  }

  cout << maxGamesWon(N, K, moves) << endl;

  return 0;
}


