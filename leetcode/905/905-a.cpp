const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       vector<int> sorted;
       for(int e: nums){
           if(e%2 == 0){
               sorted.insert(sorted.begin(),e);
           } else {
               sorted.push_back(e);
           }
       }
       return sorted; 
    }
};