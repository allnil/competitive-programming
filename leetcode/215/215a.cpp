const int ZERO = [](){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  public:

    int findKthLargest(vector<int>& nums, int k) {
     nth_element(nums.begin(), nums.end() - k, nums.end());
     return nums[nums.size() - k]; 
    }
};

