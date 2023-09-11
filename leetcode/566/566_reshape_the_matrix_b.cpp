const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       if(r * c != mat.size() * mat[0].size()){
           return mat;
       } 
       vector<vector<int>> ans(r, vector<int>(c, 0));
       int x = 0;
       int y = 0;

       for(int i = 0; i < r; i++){
           for(int j = 0; j < c; j++){
               if(x < mat[0].size()){
                   ans[i][j] = mat[y][x];
               } else {
                   y++; x = 0;
                   ans[i][j] = mat[y][x];
               }
               x++;
           }
       }
       return ans;
    }
};