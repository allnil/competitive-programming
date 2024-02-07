const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        int l = 0; int r = nums.size() - 1;
        while(l < r){
           if(nums[l] % 2 == 0){
               l++;
               continue;
           }
           if(nums[r] % 2 != 0){
               r--;
               continue;
           } 
           swap(nums[l], nums[r]); l++; r--;
        } 
       return nums; 
    }
};