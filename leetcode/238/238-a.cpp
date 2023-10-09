const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
       vector<int> ans(n.size(), 1);

        int prodPrefix = 1;
        int prodSuffix = 1;

       for(int i = 0; i < n.size(); i++){
            ans[i] *= prodPrefix;
            prodPrefix *= n[i];
       } 

       for(int i = n.size() - 1; i >= 0; i--){
            ans[i] *= prodSuffix;
            prodSuffix *= n[i];
       } 
       return ans;
    }
};