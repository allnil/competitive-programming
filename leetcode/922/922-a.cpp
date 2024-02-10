const int ZERO = []{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        if(nums.size() == 1){
            return nums;
        }

        int l = 0; int r = 1;
        while(l < nums.size() && r < nums.size()){
            if(nums[l] % 2 == 0){
                l += 2;
                continue;
            }  
            if(nums[r] % 2 != 0){
                r += 2;
                continue;
            } 
            swap(nums[l], nums[r]);
            l += 2; r += 2; 
        } 

        return std::move(nums);
    }
};