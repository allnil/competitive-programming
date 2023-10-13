class Solution {

    int choose(int n, int k){
        k = min(k, n - k);
        long long result = 1;
        for(int i = 1; i <= k; i++){
            result = result * (n - k + i)/ i;
        }
        return (int)result;
    }

public:
    int uniquePaths(int m, int n) {
       return choose(n + m - 2, m - 1);
    }
};