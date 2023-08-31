#include <vector>
#include <iostream>

using namespace std;
class Solution {
    void distance(vector<vector<int>>& dp, const string& s1, const string& s2){
        int m = s1.size();
        int n = s2.size();
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0){
                    dp[i][j] = j;
                } else if (j == 0){
                    dp[i][j] = i;
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])});
                }
            }
        }
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        
        distance(dp, word1, word2);

        return dp[word1.size()][word2.size()];
    }
};
