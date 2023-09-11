const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> matrixReshape(const vector<vector<int>>& nums1, int r2, int c2) {
        int r1 = (int)nums1.size();
        int c1 = (int)nums1[0].size();

       if(r1 * c1 != c2 * r2 || (r1 == r2 && c1 == c2)){
           return nums1;
       } 

       vector<vector<int>>nums2 (r2, vector<int>(c2));
        for(int i = 0; i < r1*c1; i++)
        {
            nums2[i/c2][i%c2] = nums1[i/c1][i%c1];
        }
       return nums2;
    }
};