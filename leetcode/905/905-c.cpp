const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 1;
}();


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l, r = 0;
        while(l < nums.size() && r < nums.size()){
            if(nums[r] % 2 == 0) {
                swap(nums[l], nums[r]);
                l++; r++;
                continue;
            }
            r++;
        }
       return nums; 
    }
};